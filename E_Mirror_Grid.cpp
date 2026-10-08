#include <bits/stdc++.h>
using namespace std;
/* 
    Solved By :
        Your_Fav_Varsh

*/
void solution() {
    int n ; cin >>n ;
    vector<string> grid(n);

    for(string &x : grid) cin >> x ;

    int ans = 0 ; 

    for(int i = 0 ; i < n/2;i++){
        for(int j = 0 ; j<(n+1)/2;j++){
            int ones = 0 ; 

            if(grid[i][j]== '1')ones++;
            if(grid[n-1 -i][n-1-j ]== '1')ones++;
            if(grid[j][n-1-i]== '1')ones++;
            if(grid[n-1-j][i]== '1')ones++;

            ans +=min(ones , 4-ones);
        }
    }
    cout << ans<< endl;
    return; 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}