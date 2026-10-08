#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    
    bool found67 = false;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (a == 67) {
            found67 = true;
        }
    }
    
    if (found67) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}