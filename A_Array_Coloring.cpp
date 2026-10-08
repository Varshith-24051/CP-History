#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; 
    cin>>n; 
    vector<int> a(n);
    for( int i =0 ; i < n ; i++) cin>>a[i];
    int even = 0, odd = 0; 
    for ( int i =0 ; i < n ; i++){
        if(a[i]%2==1) odd++;
    }

    if( odd%2==1){
        cout<<"NO"<<endl;
        return;
    }
    else {
        cout<<"YES"<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin >> t ; 
    while(t--){
        solution();
    }
    return 0;
} 
