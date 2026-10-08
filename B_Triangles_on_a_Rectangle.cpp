#include <bits/stdc++.h>
using namespace std;

void solution(){ 
    long long ans = 0;
    long long w, h; 
    cin >> w >> h; 

    for(int side = 0; side < 4; side++){
        int n; 
        cin >> n; 

        long long first, last, x;
        for(int j = 0; j < n; j++){
            cin >> x;
            if(j == 0) first = x;
            if(j == n-1) last = x;
        }

        long long base = last - first;
        if(side <= 1)
            ans = max(ans, base * h); 
        else
            ans = max(ans, base * w);  
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 
    while(t--) solution();
    return 0;
}
