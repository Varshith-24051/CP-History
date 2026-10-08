#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans12, ans23, ans45, ans56;
    
    cout << "? 1 2" << endl; 
    cin >> ans12;
    
    cout << "? 2 3" << endl;
    cin >> ans23;
    
    cout << "? 4 5" << endl;
    cin >> ans45;
    
    cout << "? 5 6" << endl;
    cin >> ans56;

    vector<int> p = {4, 8, 15, 16, 23, 42};

    do {
        if (p[0] * p[1] == ans12 && 
            p[1] * p[2] == ans23 && 
            p[3] * p[4] == ans45 && 
            p[4] * p[5] == ans56) {
            
            cout << "! " << p[0] << " " << p[1] << " " << p[2] << " " 
                 << p[3] << " " << p[4] << " " << p[5] << endl;
            return 0; 
        }
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}