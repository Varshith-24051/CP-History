#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solution() {
    ll n, k; 
    cin >> n >> k; 
    
    vector<ll> a(n);
    ll summ = 0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        summ += a[i];
    }
    
    vector<int> time(n, 0); 
    int last_flush_time = -1; 
    ll flush_val = 0;         
    for(int timer = 1; timer <= k; timer++) {
        int op; 
        cin >> op; 
        
        if(op == 1) {
            ll i, x; 
            cin >> i >> x; 
            i--; 

            ll current_val;
            if (time[i] > last_flush_time) {
                current_val = a[i]; 
            } else {
                current_val = flush_val; 
            }

            summ -= current_val;
            summ += x;
            a[i] = x;
            time[i] = timer;
            
            cout << summ << "\n";
        } 
        else if(op == 2) {
            ll x; 
            cin >> x;
            summ = x * n;

            flush_val = x;
            last_flush_time = timer;
            
            cout << summ << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solution();
    return 0;
}