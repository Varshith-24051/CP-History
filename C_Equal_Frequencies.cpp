#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; cin >> n; 
    string s; cin >> s;

    vector<pair<int, char>> v(26);
    for(int i = 0; i < 26; i++){
        v[i].first = 0;
        v[i].second = 'a' + i;
    }
    
    for(int i = 0; i < n; i++){
        v[s[i] - 'a'].first++;
    }

    sort(v.rbegin(), v.rend());
    
    int kk = 1, ans = n; 
    
    for(int k = 1; k <= 26; k++){
        if(n % k) continue;
        int temp = 0; 
        for(int i = 0; i < k; i++) {
            temp += min(v[i].first, n / k);
        }
        if(n - temp < ans) {
            ans = n - temp; 
            kk = k;
        }
    }

    map<char, int> mp; 
    for(int i = 0; i < kk; i++) mp[v[i].second] = n / kk;

    string out(n, ' ');
    
    for(int i = 0; i < n; i++){
        if (mp[s[i]] > 0) {
            out[i] = s[i]; 
            mp[s[i]]--;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(out[i] != ' ') continue; 
        
        while(!mp.empty() && (*mp.begin()).second == 0) mp.erase(mp.begin());
        char x = (*mp.begin()).first; 
        out[i] = x; 
        mp[x]--; 
    }
    
    cout << ans << "\n" << out << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}