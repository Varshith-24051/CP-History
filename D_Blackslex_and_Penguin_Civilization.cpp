#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int total = 1 << n;
    vector<int> p;
    vector<bool> used(total, false);

    int current_and = total - 1;
    
    p.push_back(current_and);
    used[current_and] = true;

    
    for (int step = 1; step < total; ++step) {
        int target_pop = __builtin_popcount(current_and);
        
        if (target_pop > 0) {
            bool found = false;
            
            int best_v = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (current_and & (1 << i)) {
                    int candidate = current_and ^ (1 << i);
                    if (!used[candidate]) {
                        best_v = candidate;
                        break; 
                    }
                }
            }
            
            if (best_v != -1) {
                p.push_back(best_v);
                used[best_v] = true;
                current_and &= best_v;
            } else {
                for (int i = 0; i < total; ++i) {
                    if (!used[i]) {
                        p.push_back(i);
                        used[i] = true;
                        current_and &= i;
                        break;
                    }
                }
            }
        } else {
            for (int i = 0; i < total; ++i) {
                if (!used[i]) {
                    p.push_back(i);
                    used[i] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < total; ++i) {
        cout << p[i] << (i == total - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}