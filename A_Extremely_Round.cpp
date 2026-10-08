#include <bits/stdc++.h>
using namespace std;

void solution(){
    string n; cin>>n;
    if( n<="10" ){
        cout<<n<<endl;
        return;
    }
    int ans = 9;
    int length = n.length();
    ans += (length-2)*9 + (n[0]-'0');
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t;
    while(t--)solution();
    return 0;
}