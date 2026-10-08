#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n; 
    cin >> n; 
    string s; 
    cin >> s;

    unordered_set<char> se;
    vector<int> arr1(n+1, 0), arr2(n+2, 0);

    for(int i = 1; i <= n; i++){
        se.insert(s[i-1]);
        arr1[i] = se.size();
    }

    se.clear();

    for(int i = n; i >= 1; i--){
        se.insert(s[i-1]);
        arr2[i] = se.size();
    }

    int ans = 0;
    for(int i = 1; i < n; i++){
        ans = max(ans, arr1[i] + arr2[i+1]);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        solution();
    }
    return 0;
}
