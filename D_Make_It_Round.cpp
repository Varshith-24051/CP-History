#include <iostream>

using namespace std;

void solution() {
    long long n, m;
    cin >> n >> m;

    long long temp_n = n;
    long long cnt2 = 0, cnt5 = 0;
    
    while (temp_n % 2 == 0) {
        cnt2++;
        temp_n /= 2;
    }
    while (temp_n % 5 == 0) {
        cnt5++;
        temp_n /= 5;
    }

    long long k = 1;

    while (cnt2 < cnt5 && k * 2 <= m) {
        cnt2++;
        k *= 2;
    }
    while (cnt5 < cnt2 && k * 5 <= m) {
        cnt5++;
        k *= 5;
    }

    while (k * 10 <= m) {
        k *= 10;
    }

    if (k == 1) {
        cout << n * m << "\n";
    } else {
        k *= (m / k);
        cout << n * k << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}