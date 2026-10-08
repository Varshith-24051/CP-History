#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (*min_element(v.begin(), v.end()) == 0 && *max_element(v.begin(), v.end()) == 0) {
        cout << 0 << "\n";
        return;
    }
    if(n%2==0){
        cout<<2<<endl;
        cout<<1<<" "<<n<<endl;
        cout<<1<<" "<<n<<endl;
        return;
    }

    
    if(n%2!=0){
        cout<<4<<endl;
        cout<<1<<" "<<n-1<<endl;
        cout<<1<<" "<<n-1<<endl;
        
        cout<<n-1<<" "<<n<<endl;
        cout<<n-1<<" "<<n<<endl;
        return;
    }
    cout << 1 << " " << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
