#include <bits/stdc++.h>
using namespace std;
#define int long long
void solution() {
    string s ; int k ; 
    cin>> s >> k; 

    int n = s.size();
    while(k> n ){
        k-=n;
        n--;
    }
    int d = s.size() - n ; 
    string temp; 
    for(auto x : s ){
        while(d > 0 && !temp.empty() && temp.back() > x){
            temp.pop_back();
            d--;
        }
        temp+=x;
    }
    cout<<temp[k-1];
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}