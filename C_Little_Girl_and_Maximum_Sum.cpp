#include <bits/stdc++.h>
using namespace std;
#define int long long 

int ans = 0; 

void solution() {

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> b(n + 1, 0);

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;           
		b[l]++;          
		b[r + 1]--;      
	}
	
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];

	sort(b.rbegin(), b.rend());
	sort(a.rbegin(), a.rend());

	for (int i = 0; i < n; i++)
		ans += a[i] * b[i];
	cout << ans << endl ;

	return ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solution();
    return 0;
}