
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int m = min(n, 200);
    int x = -1, y = -1;
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        if (a[j] % a[i] % 2 == 0) {
          x = a[i];
          y = a[j];
          break;
        }
      }
      if (x != -1) break;
    }
    if (x == -1) cout << -1 << '\n';
    else cout << x << " " << y << '\n';
  }
  return 0;
}
