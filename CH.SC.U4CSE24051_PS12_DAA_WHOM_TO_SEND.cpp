#include<bits/stdc++.h>
#include <cstdint>

using namespace std;

class ScalableStatelessRouter {
private:
    // Global UID Mapping
    unordered_map<string, int> node_to_id;
    unordered_map<int, string> id_to_node;
    int node_count = 0;

    // Adjacency List uses std::set for Lexicographical Tie-Breaking (Loop prevention)
    unordered_map<int, set<int>> adjList;
    
    // routing_tables[source_node][destination_node] = next_hop_node
    unordered_map<int, unordered_map<int, int>> routing_tables;
    
    // Lazy Evaluation Tracker (Only run BFS if the router physically receives a packet)
    unordered_map<int, bool> has_run_bfs; 

    // Helper: Assigns a contiguous integer ID to each string node name
    int getID(const string& name) {
        if (node_to_id.find(name) == node_to_id.end()) {
            node_to_id[name] = node_count;
            id_to_node[node_count] = name;
            has_run_bfs[node_count] = false;
            node_count++;
        }
        return node_to_id[name];
    }

    // Helper: Checks if all chunks in the 64-bit vector are empty
    bool isHeaderEmpty(const vector<uint64_t>& header) {
        for (uint64_t chunk : header) {
            if (chunk != 0) return false;
        }
        return true;
    }

    // Helper: Decodes the bitmask back into an array format like [C, G] for the logs
    string decodeHeader(const vector<uint64_t>& header) {
        string res = "[";
        bool first = true;
        for (int i = 0; i < node_count; ++i) {
            int chunk_idx = i / 64;
            int bit_idx = i % 64;
            if (header[chunk_idx] & (1ULL << bit_idx)) {
                if (!first) res += ", ";
                res += id_to_node[i];
                first = false;
            }
        }
        res += "]";
        return res;
    }

    // The Control Plane: Deterministic BFS (Runs only once per active router)
    void buildRoutingTableForNode(int source) {
        queue<pair<int, int>> q; // {current_node, first_hop_taken}
        vector<bool> visited(node_count, false);

        visited[source] = true;
        routing_tables[source][source] = source;

        for (int neighbor : adjList[source]) {
            q.push({neighbor, neighbor});
            visited[neighbor] = true;
            routing_tables[source][neighbor] = neighbor;
        }

        while (!q.empty()) {
            auto [current, first_hop] = q.front();
            q.pop();

            // set ensures alphabetical traversal, mathematically preventing loops
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    routing_tables[source][neighbor] = first_hop;
                    q.push({neighbor, first_hop});
                }
            }
        }
    }

public:
    // Builds the physical topology
    void addLink(const string& u_str, const string& v_str) {
        int u = getID(u_str);
        int v = getID(v_str);
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    // NEW HELPER: Prints the exact binary state of the header (sized to node_count)
    string toBinaryString(const vector<uint64_t>& header) {
        string res = "";
        // Print from MSB (highest node ID) down to LSB (Node 0)
        for (int i = node_count - 1; i >= 0; --i) {
            int chunk_idx = i / 64;
            int bit_idx = i % 64;
            if (header[chunk_idx] & (1ULL << bit_idx)) {
                res += "1";
            } else {
                res += "0";
            }
            if (i % 4 == 0 && i != 0) res += " "; // Add space every 4 bits for readability
        }
        return res;
    }

    // UPDATED DATA PLANE: Now with bitwise hardware tracing
    void forwardPacket(const string& start_node, const vector<string>& targets) {
        int source_id = getID(start_node);
        int num_chunks = (node_count / 64) + 1; 
        
        vector<uint64_t> initial_header(num_chunks, 0);
        for (const string& target : targets) {
            int t_id = getID(target);
            initial_header[t_id / 64] |= (1ULL << (t_id % 64));
        }

        queue<pair<int, vector<uint64_t>>> network;
        network.push({source_id, initial_header});

        int step = 1;

        while (!network.empty()) {
            auto [u, header] = network.front();
            network.pop();

            if (!has_run_bfs[u]) {
                buildRoutingTableForNode(u);
                has_run_bfs[u] = true;
            }

            cout << "\n======================================================\n";
            cout << "STEP " << step++ << ": [ROUTER " << id_to_node[u] << "] Processing Packet\n";
            cout << "  -> Incoming Header (Binary): " << toBinaryString(header) << "  " << decodeHeader(header) << "\n";

            int chunk_u = u / 64;
            int bit_u = u % 64;

            // STRIPPING PHASE Trace
            if (header[chunk_u] & (1ULL << bit_u)) {
                cout << "  -> MATCH: Router " << id_to_node[u] << " is a target. Delivering payload.\n";
                cout << "  -> EXEC:  header &= ~(1ULL << " << bit_u << ")  [Bitwise AND NOT]\n";
                header[chunk_u] &= ~(1ULL << bit_u); 
                cout << "  -> Resulting Header        : " << toBinaryString(header) << "\n";
            }

            if (isHeaderEmpty(header)) {
                cout << "  -> Header is empty (all 0s). Packet terminates here.\n";
                continue;
            }

            // PARTITIONING PHASE Trace
            map<int, vector<uint64_t>> outbound_packets; 
            cout << "  -> Partitioning remaining targets...\n";
            
            for (int dest = 0; dest < node_count; ++dest) {
                int chunk_d = dest / 64;
                int bit_d = dest % 64;
                // NEW: Edge-case safety check for disconnected networks!
                if (routing_tables[u].find(dest) == routing_tables[u].end()) {
                    cout << "     * Target " << id_to_node[dest] << " is UNREACHABLE. Dropping from header.\n";
                    continue; 
                }
                
                int next_hop = routing_tables[u][dest]; // (This line already exists)
                if (header[chunk_d] & (1ULL << bit_d)) {
                    int next_hop = routing_tables[u][dest];
                    
                    if (outbound_packets.find(next_hop) == outbound_packets.end()) {
                        outbound_packets[next_hop] = vector<uint64_t>(num_chunks, 0);
                    }
                    
                    outbound_packets[next_hop][chunk_d] |= (1ULL << bit_d); 
                    cout << "     * Target " << id_to_node[dest] << " (Bit " << bit_d << ") maps to Link [" << id_to_node[u] << "->" << id_to_node[next_hop] << "]\n";
                }
            }

            // FORWARDING PHASE Trace
            cout << "  -> Forwarding Packets:\n";
            for (const auto& [next_node, new_header] : outbound_packets) {
                cout << "     [FIRE] Link " << id_to_node[u] << " -> " << id_to_node[next_node] << "\n";
                cout << "            Outbound Header: " << toBinaryString(new_header) << "  " << decodeHeader(new_header) << "\n";
                network.push({next_node, new_header});
            }
        }
    }
};

int main() {
    ScalableStatelessRouter router;

    // Constructing the exact network graph from the problem
    router.addLink("S", "A");
    router.addLink("S", "B");
    router.addLink("A", "C");
    router.addLink("A", "D");
    router.addLink("B", "E");
    router.addLink("B", "F");
    router.addLink("D", "G");
    router.addLink("C", "G"); 

    cout << "--- Starting SBM-DSPT Forwarding Architecture ---\n\n";
    
    // Launching the Explicit Multicast
    router.forwardPacket("S", {"C", "F", "G"});
    
    cout << "--- Routing Complete ---\n";

    return 0;
}