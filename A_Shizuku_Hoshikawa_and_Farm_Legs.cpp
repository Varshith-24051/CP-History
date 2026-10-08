#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; cin>> n;
    if( n%2==0 ||n%4==0){
        int ans =0 ; 
        for(int i = 0 ; i < n ; i++){
            for( int j =0 ; j< n ;j++ ){
                if(2*i+4*j == n )ans++;
                if(2*i+4*j > n ){
                    break;
                }
            }
        }cout<< ans<<endl;

    }
    else{
        cout<<0<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin >> t ; 
    while(t--)solution();
    return 0;
}