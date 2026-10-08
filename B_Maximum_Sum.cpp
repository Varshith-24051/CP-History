#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 

void solution() {
	int n , k ; 
	cin >> n >> k ; 
	vector<ll> a(n);
	for(ll& x :a )cin >> x ; 
	ll max_sum = 0 ; 
	vector<ll> prefix(n); 
	sort(a.begin(),a.end());
	prefix[0] = a[0];
	for( ll i = 1; i < n ; i ++){
		prefix[i] = a[i] + prefix[i-1];
	}

	for(int first = 0 ; first<=k ;first++){
		ll  second =2*( first ) ;
		ll a = n - k + first - 1; 
		max_sum = max(max_sum , prefix[a]- (second==0 ? 0:prefix[second -1])); 
	}
	cout<<max_sum<< endl ; 
	return; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;
	while (t--) solution();
	return 0;
}