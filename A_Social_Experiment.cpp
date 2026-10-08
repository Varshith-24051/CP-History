#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    if (n == 2) {
        std::cout << 2 << "\n";
    } else if (n == 3) {
        std::cout << 3 << "\n";
    } else {
        // If n is even (>= 4), diff is 0
        // If n is odd (>= 5), diff is 1
        std::cout << (n % 2) << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}