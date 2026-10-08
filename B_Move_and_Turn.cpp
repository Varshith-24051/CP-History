#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (cin >> n) {
        long long k = n / 2; 
        
        if (n % 2 == 0) {
            cout << (k + 1) * (k + 1) << endl ;
        } else {
            cout << 2 * (k + 1) * (k + 2) << endl;
        }
    }
    
    return 0;
}