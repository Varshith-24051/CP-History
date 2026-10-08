#include <bits/stdc++.h>
using namespace std;

long long ceil_division(long long a, long long b) {
	return (a + b - 1) / b;
}

int main() {
	int t;
	cin >> t; 
	while (t--) {
		long long x, y, k;
		cin >> x >> y >> k; 
		long long s = x - 1; 

		long long ss = k * y + k - 1;

		long long trades = 0;
		trades += ceil_division(ss, s);
		trades += k;


		cout << trades << endl;
	}
}
