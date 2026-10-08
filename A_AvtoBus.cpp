#include <bits/stdc++.h>
using namespace std;

void solution(){
    long long  n ; 
    cin >>n;
    if ( n<4||n%2==1){
        cout<<-1<<endl;
        return;
    }
    else{
        long long minn = (n+5)/6;
        long long maxx = ( n/4);
        cout<< minn << " "<< maxx << endl; 
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t;
    while(t--)solution();
    return 0;
}
