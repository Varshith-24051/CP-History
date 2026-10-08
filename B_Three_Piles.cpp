#include <bits/stdc++.h>
using namespace std;

void solution() {
    int a,b,c; cin>> a >> b>> c; 
    cout<<max(abs(a-b),abs(a-b+c))<<endl;
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