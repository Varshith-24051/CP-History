#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    // no for this you have to find the natire of the i th index for which it has powers ( 1 - 0 ) 
    
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> b(n);
    for (int& x : b) cin >> x;

    int k_star = -1; 
    
    for (int k = 19; k >= 0; --k) {
        int c_k = 0; 
        for (int i = 0; i < n; ++i) {
            int a_ik = (a[i] >> k) & 1;
            int b_ik = (b[i] >> k) & 1;
            
            c_k ^= (a_ik ^ b_ik);
        }

        if (c_k == 1) {
            k_star = k;
            break;
        }
    }


    if (k_star == -1) {
        cout << "Tie" << endl;
        return;
    }

    int na_kstar = 0; 
    int nm_kstar = 0; 

    for (int i = 0; i < n; ++i) {
        int a_ik = (a[i] >> k_star) & 1;
        int b_ik = (b[i] >> k_star) & 1;

        if (a_ik != b_ik) {
            if ((i + 1) % 2 != 0) { 
                na_kstar++;
            } 
            else {
                nm_kstar++;
            }
        }
    }

    if (na_kstar >= nm_kstar) {
        cout << "Ajisai" << endl;
    } else {
        cout << "Mai" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}