#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int sizee, numb;
    cin >> sizee >> numb;
    int min_steps = (sizee + 1) / 2;
    int ans = -1;
    for (int x = min_steps; x <= sizee; x++) {
        if (x % numb == 0) {
            ans = x;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}