#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list <int> *l;
    public:
    Graph(int V){
        this->V=V;
        l = new list<int>[V];
        //arr = new int[V];
    }
    void add_Edge_undirected(int u, int v ){// for undirected edge;
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void  print_graph(){
        for( int i =0; i < V; i++){
            cout<<i << " : ";
            for( auto node : l[i]){
                cout<< node << " ";
            }
            cout<<endl;
        }
    }
    void bsf (){//O(V+E);
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(0);
        visited[0] = true;
        while(q.size()>0){
            int u = q.front();
            q.pop();

            cout<< u << " ";
            for ( auto v : l[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
            cout<<endl;
    }
}
    void dsf(int u , vector <bool> &visited){
        cout<< u<<" ";
        visited[u] = true;
        for( auto v : l[u]){
            if(!visited[v]){
                dsf(v, visited);
            }
    }
}
//start of isCycle ----------------------------------------------
bool isCycleUndirDSF(int src, int par, vector <bool> &visited){
    visited[src]= true;
    list<int> neighbors = l[src];

    for(int v : neighbors){
        if(!visited[v]){
            if(isCycleUndirDSF(v, src, visited)){
                return true;
            }
        }else if(v != par){
            return true;
    }
}
return false;
}
bool isCycle(){
    vector<bool> visited(V,false);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            if(isCycleUndirDSF(i, -1, visited)){
                return true;
            }
        }
    }
    return false;
}//END of isCycle -----------------------------------------------------

};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // DFS means first immediate next non visited elements //
    // BSF means immediate next non visited elements in all direction [Queues, vectors]//
    Graph UG(5);
    UG.add_Edge_undirected(0, 1);
    UG.add_Edge_undirected(0, 4);
    UG.add_Edge_undirected(1, 2);
    UG.add_Edge_undirected(1, 3);
    UG.add_Edge_undirected(1, 4);

    UG.print_graph();
    UG.bsf();
    vector <bool> visited(5, false);
    UG.dsf(0, visited);
    if(UG.isCycle()){
        cout<<"Cycle detected";
    }else{
        cout<<"No Cycle detected";
    }
    return 0;
}