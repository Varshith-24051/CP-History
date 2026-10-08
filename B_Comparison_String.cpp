#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n;
    string a;
    cin >> a;
    
    int curr = 1, length = 1 ;
    for( int i = 0 ; i+1 < n ; i++){
        if(a[i]!=a[i+1]){
            length= max( length, curr);
            curr=1;
        }
        else{curr++;}
    }
    length= max( length, curr);
    cout<<length+1<<endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
