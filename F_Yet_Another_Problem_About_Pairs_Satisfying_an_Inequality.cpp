#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n; 
    
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    
    vector<int> comp(n + 1, 0); 
    
    for(int i = 1; i <= n; i++){

        comp[i] = comp[i - 1]; 
        
        if(v[i] < i){
            comp[i]++;
        }
    }
    
    long long total_pairs = 0; 
    
    for(int j = 1; j <= n; j++){

        if(v[j] < j){
            int required_index = v[j] - 1;
            if(required_index > 0){
                total_pairs += comp[required_index];
            }
        }
    }
    cout << total_pairs << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}