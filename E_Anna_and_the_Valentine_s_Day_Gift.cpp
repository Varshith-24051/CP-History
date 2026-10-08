#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n, m;
		cin >> n >> m;
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];

		int totalDigits = 0;              
		int trailingZeroes[n]{};            
		for (int i = 0; i < n; i++) {       
				while (arr[i] % 10 == 0) {    
						trailingZeroes[i]++;
						arr[i] /= 10;
						totalDigits++;         
				}
				while (arr[i] > 0) {          
						totalDigits++;
						arr[i] /= 10;
				}
		}

		sort(trailingZeroes, trailingZeroes + n, greater<>()); 
		for (int i = 0; i < n; i += 2) {    
				totalDigits -= trailingZeroes[i];
		}

		if (totalDigits > m)
				cout << "Sasha\n";
		else
				cout << "Anna\n";
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}

}
