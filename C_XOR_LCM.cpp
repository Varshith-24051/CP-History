#include <bits/stdc++.h>
using namespace std;
#define int long long
void solution() {
    int c; cin>> c ; 
    int a  = c ;
    int b =1;
    while(c){
        b<<=1;
        c>>=1;
    }
    b*=a;
    cout<<a<<" "<<b<<endl;
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