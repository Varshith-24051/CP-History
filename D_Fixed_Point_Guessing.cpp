#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) exit(0);
    
    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        cout << "? " << l << " " << mid << endl;
        
        int count = 0;
        int len = mid - l + 1;
        
        for (int i = 0; i < len; ++i) {
            int x;
            cin >> x;
            
            if (x == -1) {
                exit(0);
            }
            
            if (x >= l && x <= mid) {
                count++;
            }
        }
        
        if (count % 2 != 0) {
            r = mid;
        } 
        else {
            l = mid + 1;
        }
    }
    
    cout << "! " << l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}