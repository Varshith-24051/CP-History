// #include <bits/stdc++.h>
// using namespace std;

// void solution() {
     
//     int n  ;cin >> n ; 
//     int k ; cin >> k ; 

//     vector<int> a(n);

//     for(int &x:a)cin >> x; 

//     for(int x : a ){
//         if(find(a.begin(), a.end(), x-k) != a.end()){
//             cout<<"YES"<<endl;
//             return;
//         }
//     }
//     cout<<"NO"<<endl;
//     return;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     cin >> t;
//     while (t--) solution();
//     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     int n;
//     long long k;
//     cin >> n >> k;

//     unordered_set<long long> st;
//     vector<long long> a(n);

//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         st.insert(a[i]);   
//     }

//     for (auto x : a) {
//         if (st.find(x - k) != st.end()) {
//             cout << "YES\n";
//             return;
//         }
//     }

//     cout << "NO\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }

#include <bits/stdc++.h>
using namespace std;

// void solve() {
//     int n;
//     long long k;
//     cin >> n >> k;

//     vector<long long> a(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     sort(a.begin(), a.end());

//     int l = 0, r = 1;

//     while (r < n) {
//         long long diff = a[r] - a[l];

//         if (diff == k) {
//             cout << "YES\n";
//             return;
//         }
//         else if (diff < k) {
//             r++;
//         }
//         else {
//             l++;
//             if (l == r) r++;
//         }
//     }

//     cout << "NO\n";
// }
void solve() {
	ll n, k;
	cin >> n >> k; // Read the number of integers in the list and the target value
	vector<ll> v(n); // Declare a vector to store the list of integers

	// Read the list of integers
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	map<ll, bool> mp; // Map to store the presence of each integer in the list

	// Populate the map with the integers from the list
	for (auto it : v) {
		mp[it] = true;
	}

	// Check if there exists an element such that element - k is also in the list
	for (int i = 0; i < n; i++) {
		if (mp.find(v[i] - k) != mp.end()) {
			cout << "YES" << endl; // If found, print "YES"
			return;
		}
	}

	cout << "NO" << endl; // If no such element is found, print "NO"

	// Time Complexity (TC): O(nlogn)
	// Space Complexity (SC): O(n)
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
