#include <bits/stdc++.h>
using namespace std;

void solution(){
    int a, b, c;
    cin>>a>>b>>c;
    bool ans = false ;
    long long newa = 2*b-c;
    if( newa/a > 0 && newa %a ==0 )ans=true;
    long long newb = (a+c)/2;
    if( newb /b > 0 && newb%b ==0 && (c-a)%2==0)ans = true ; 
    long long newc = 2*b-a;
    if( newc/c> 0 &&newc%c ==0 )ans =true ; 
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t; 
    while(t--)solution();
    return 0;
}