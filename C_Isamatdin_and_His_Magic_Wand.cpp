#include <bits/stdc++.h>
using namespace std;
void solution(){
    int n;
    cin>> n;
    vector<int> v(n);
    for( int i = 0 ; i < n; i++ ) cin>> v[i];
    int flow = v[0] % 2;
    for( int i = 1 ; i < n; i++ ){
        if( v[i] % 2 != flow ){
            flow = 5 ;
            break;
        }
    }
    if( flow==5){
        sort(v.begin(), v.end());
        for( int x : v ){
            cout<< x << " ";
        }
        cout<<endl;
    }
    else{
        for( int x : v ){
            cout<< x << " ";
        }
        cout<<endl;
}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
       solution();
    }
    return 0;
}