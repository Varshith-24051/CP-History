#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int penalty = 0;
    int x = 1e9; 
    int y = 1e9; 

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        if (x > y) {
            swap(x, y);
        }

        if (a <= x) {
            x = a;
        } 
        else if (a <= y) {
            y = a;
        } 
        else {
            x = a;
            penalty++;
        }
    }
    
    cout << penalty << "\n";
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