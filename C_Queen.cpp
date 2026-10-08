#include <bits/stdc++.h>
using namespace std;

void solution() {
    
   int n ; cin >> n ; 
   vector<int> p(n+1) , c ( n+1 ) , del(n+1); 

   for( int i = 1 ; i <=n ; i++){
    cin >> p[i] >> c[i];
    del[i] = c[i];
   }

   for(int i = 1 ; i <= n  ; i++){
    if(c[i] == 0 && p[i] != -1)del[p[i]]= 0; 
   }

   int print = 0 ;
   for(int i = 1 ; i <= n ; i++){
    if(del[i]) {cout<< i<< " "; print = 1 ;} 
   }
   if(print == 0 )cout << -1 ;
   cout << endl ;
   return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     solution();
    return 0;
}