#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n; 
    vector<int> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int one = 0, zero = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) one++;
        else zero++;
    }
    if(zero > one) {
        cout << "Elsie" << "\n";
    } else {
        cout << "Bessie" << "\n";
    }
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}