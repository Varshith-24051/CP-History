/*
Solution By: Your_Fav_Varsh
*/
#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, k;
    if (!(cin >> n >> k)) return;

    int freq[100001] = {0};
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        freq[val]++;
    }

    int count = 0;
    for (int i = 0; i <= 100000; i++) {
        if (freq[i] > 0) {
            count += freq[i];
            if (count >= k) {
                cout << i << "\n";
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solution();
    
    return 0;
}