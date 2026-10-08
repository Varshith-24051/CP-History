#include <bits/stdc++.h>
using namespace std;
// first element compare , construct arrays with respect to that 
void solution() {
    int n; 
    cin >>n; 
    vector<int>a(n);
    for( int i= 0 ; i < n ; i++)cin>>a[i];
    sort(a.begin(), a.end());
    vector<int>b,c;
    for(int i = 0 ; i < n ; i++){
        if(a[0]%a[i]==0){
            b.push_back(a[i]);
        }
        else{
            c.push_back(a[i]);
        }
    }
    if(b.empty()||c.empty())cout<<-1<<endl;
    else{
        cout<<b.size()<<" "<<c.size()<<endl;
        for(int x : b ) cout<<x<<" ";
        cout<<endl;
        for(int x : c ) cout<<x<<" ";
        cout<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t;
     while(t--){
        solution();
     }
    return 0;
}