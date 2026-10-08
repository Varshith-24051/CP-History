#include <iostream>

using namespace std;

void solve() {
    long long n, m, d;
    cin >> n >> m >> d;
    
   
    long long max_boxes_per_tower = (d / m) + 1;
    
    
    long long min_towers = (n + max_boxes_per_tower - 1) / max_boxes_per_tower;
    
    cout << min_towers << "\n";
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