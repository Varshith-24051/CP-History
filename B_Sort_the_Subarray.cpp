#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ; cin >> n ; 
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int l = 0 ; int r = n-1; 
    while(l<n && a[l] == b[l])l++;

    while(r>=0 && a[r] == b[r])r--;

    while(l>0 && b[l] >=b[l-1])l--;
    while(r<n-1 && b[r] <= b[r+1])r++;
    
        cout<< l+1<< " "<<r+1<<endl; 
    
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