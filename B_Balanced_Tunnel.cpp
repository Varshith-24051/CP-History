#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i]; 
    for (int i = 0; i < n; i++) cin >> b[i]; 

    vector<bool> exited(n + 1, false); 
    
    int p1 = 0; 
    int p2 = 0; 
    int fines = 0;

    while (p1 < n && p2 < n) {

        if (exited[a[p1]]) {
            p1++;
            continue;
        }

        if (a[p1] == b[p2]) {
            exited[a[p1]] = true; 
            p1++;
            p2++;
        } 
        else {
            fines++;
            exited[b[p2]] = true; 
            p2++;
        }
    }
    cout << fines << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}