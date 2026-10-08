#include <bits/stdc++.h>
using namespace std;

void solution(){
    int a , b , c;
    cin>>a>>b>>c;

    if(a+(c%2)>b){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>> t; 
    while(t--){
        solution();
    }
    return 0;
}
