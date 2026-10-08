#include <bits/stdc++.h>
using namespace std;

void solution() {
     
    int n ; cin >> n ; 
    vector<int> x(n) ; 
    for(int &a : x ) cin >> a ; 
    vector<int> y(n) ; 
    for(int &a : y ) cin >> a ;

    vector<int> res(n); 
    for(int i = 0 ; i < n ;i++){
        res[i] = y[i] - x[i];
    }
    sort(res.begin(), res.end());

    int left = 0 ,right = n-1; 
    int ans = 0 ; 
    while(left<right){

        while(res[left] + res [right]<0 && left< right){
            left++; 
        }

        if(res[left] + res [right]>=0 && left < right){ ans++;
        left++; 
        right--;
    }
    }
    cout<<ans<<endl;
    return ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}