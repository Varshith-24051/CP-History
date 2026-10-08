#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n, k;
    cin >> n >> k;

    int temp = 0;
    int x = n - 1;  
    if (x % 4 == 0) {
        temp = x;
    } else if (x % 4 == 1) {
        temp = 1;
    } else if (x % 4 == 2) {
        temp = x + 1;
    } else {
        temp = 0;
    }

    if (temp == k) {
        cout << n << "\n";
    }
    else if ((temp ^ k) != n) {
        cout << n + 1 << "\n";
    }
    else {
        cout << n + 2 << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ;
    while(t--)solution();
    return 0;
}