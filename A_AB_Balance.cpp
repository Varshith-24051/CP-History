#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();

        int AB = 0, BA = 0;
        for(int i = 1; i < n; i++){
            if(s[i-1] == 'a' && s[i] == 'b') AB++;
            if(s[i-1] == 'b' && s[i] == 'a') BA++;
        }

        if(AB == BA){
            cout << s << "\n";
        } 
        else if(AB > BA) {
            // Need more BA → set last char to 'a'
            s[n-1] = 'a';
            cout << s << "\n";
        } 
        else {
            // Need more AB → set last char to 'b'
            s[n-1] = 'b';
            cout << s << "\n";
        }
    }
}
