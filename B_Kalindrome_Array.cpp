#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, int x){
    int l = 0, r = (int)a.size() - 1;

    while(l < r){
        if(a[l] == x){
            l++;
            continue;
        }
        if(a[r] == x){
            r--;
            continue;
        }
        if(a[l] != a[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = n - 1;

    while(l < r && a[l] == a[r]){
        l++;
        r--;
    }

    if(l >= r){
        cout << "YES\n";
        return;
    }

    if(check(a, a[l]) || check(a, a[r]))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        solve();
}
