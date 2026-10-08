#include <bits/stdc++.h>
using namespace std;

void solution() {
    
    int n , m ; cin >>n >> m ; 
    vector<int> a(m);
    vector<int> freq(n+1,0);
    for(int x: a ){
        cin >> x ; 
        freq[x]++;
    }
int low = 0, high = 2 * m;
    
    while(low < high) {
        int mid = low + (high - low) / 2; 
        long long temp = 0; 

        for(int i = 1; i <= n; i++) { 
            if(freq[i] > mid) {
                temp += mid; 
            } else {
                temp += freq[i] + (mid - freq[i]) / 2;
            }
        }
        
        if(temp >= m) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    cout << low << endl; 
    return; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}