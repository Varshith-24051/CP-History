#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; cin>> n ; 
    n--;
    long long msb  = log2(n);

    int temp = pow(2,msb) -1;
    while(temp>=0){

        cout<< temp <<" ";
        temp--;
    }
    temp = pow(2,msb);
    while(temp<= n){
        cout<<temp<<" ";
        temp++;
    }
    cout<< endl; 
    return;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ;
     while(t--) solution();

    return 0;
}