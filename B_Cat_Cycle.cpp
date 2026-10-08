#include <bits/stdc++.h>
using namespace std;
/* 
    Solved By :
        Your_Fav_Varsh

*/
void solution() {
    int n , k ; cin >> n >> k ; 
    if(n %2 == 0 ){
        cout << ((k-1)%n) + 1 <<endl ; 
        return;
    }
    else{
        cout<<((k-1) + ( (k-1)/(n/2)))% n +1 <<endl ;
        return; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}