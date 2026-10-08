#include <bits/stdc++.h>
using namespace std;

vector<int> p, sizee; 

int find(int a) {
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(sizee[a] < sizee[b]) swap(a, b);
        p[b] = a;
        sizee[a] += sizee[b];
    }
}

void solution() {
    int n, m; 
    cin >> n >> m;
    
    p.resize(n); 
    for(int i = 0; i < n; i++) p[i] = i;
    
    sizee.resize(n, 1);
     
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k; 
        if(k > 0) {
            int first;
            cin >> first; 
            first--;
            for(int j = 1; j < k; j++) {
                int a; 
                cin >> a; 
                a--; 
                join(first, a);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << sizee[find(i)] << " "; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
    return 0;
}