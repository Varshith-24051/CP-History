#include <bits/stdc++.h>
using namespace std;

void solution() {
     int n ; cin >> n ; 
     vector<int>a(n); 
     for(int& x : a)cin >> x ; 
     int y = *min_element(a.begin(),a.end());
     int aumm = accumulate(a.begin(),a.end(),0);
     cout<<aumm-2*y<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}