#include <bits/stdc++.h>
using namespace std;

void solution(){
    string s ;  cin >> s ; 
    int count_0 = 0 , count_1 = 0 ;
    for(auto c : s){
        if(c == '0') count_0++;
        else count_1++;
    }
    int length_t = 0; 

    for( int i = 0; i < s.size();i++){
        if(s[i]=='1'&&count_0 > 0){
            length_t ++;
            count_0--;
        }
        else if(s[i]=='0'&&count_1>0){
            length_t++;
            count_1--;
        }
        else break;
    }
    cout<<s.size()-length_t<<"\n";
    return;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ;
     while(t--)solution();
    return 0;
}