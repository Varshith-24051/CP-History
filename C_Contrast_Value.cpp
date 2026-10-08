#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ; cin >> n ; 
    vector<int> a(n) ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;

    int ans = n ; 
    int flow = 0 ; 
    if(n == 1){
        cout<<1<< endl;
        return ;
    }
    for( int i = 1 ; i < n ;i++){
        if(a[i] == a[i-1]){
            ans--;
        }
        else if (a[i]<a[i-1]){
            if(flow ==2)ans--;
            else{
                flow = 2;
            }
        }
        else if (a[i]>a[i-1]){
            if(flow ==1)ans--;
            else{
                flow = 1 ;
            }
        }
    }
    cout<<ans<<endl;
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