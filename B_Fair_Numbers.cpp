#include <bits/stdc++.h>
using namespace std;

bool ans(long long n) {
	long long num = n;
	while (num != 0) {
		int x = num % 10; 
		if (x != 0 && n % x != 0) {
			return false;
		}
		num /= 10; 
	}
	return true; 
}

int main() {
	int t;
	cin >> t; 

	while (t--) {
		long long n;
		cin >> n; 
		while (!ans(n)) {
			n += 1;
		}

		cout << n << endl; 
	}
}