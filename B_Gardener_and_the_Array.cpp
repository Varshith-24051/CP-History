#include <bits/stdc++.h>
using namespace std;

const int MAX_BIT = 200005;
int b[MAX_BIT]; 

void solution() {
    int n; 
    cin >> n; 
    
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        while(x--) {
            int y; 
            cin >> y; 
            a[i].push_back(y);
            b[y]++; 
        }
    }
    
    bool found = false;
    for(auto& x : a) {
        int temp = 1; 
        for(int y : x) {
            if(b[y] <= 1) {  
                temp--; 
                break; 
            }
        }
        if(temp) {
            found = true;
            break; 
        }
    }
    
    if(found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    for(auto& x : a) {
        for(int y : x) {
            b[y] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}