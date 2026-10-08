#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<int> get_blocks(const vector<int>& arr) {
    vector<int> blocks;
    int current_len = 0;
    
    for (int x : arr) {
        if (x == 1) {
            current_len++;
        } else {
            if (current_len > 0) {
                blocks.push_back(current_len);
            }
            current_len = 0;
        }
    }
    if (current_len > 0) {
        blocks.push_back(current_len);
    }
    return blocks;
}

int count_fits(const vector<int>& blocks, int size) {
    int fits = 0;
    for (int len : blocks) {
        if (len >= size) {
            fits += (len - size + 1); 
        }
    }
    return fits;
}

void solution() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> blocksA = get_blocks(a);
    vector<int> blocksB = get_blocks(b);

    int ans = 0;

    for (int w = 1; w * w <= k; w++) {
        if (k % w == 0) {
            int h = k / w; 
            
            if (w <= n && h <= m) {
                int waysA = count_fits(blocksA, w);
                int waysB = count_fits(blocksB, h);
                ans += (waysA * waysB);
            }
            
            if (w != h) {
                if (h <= n && w <= m) {
                    int waysA = count_fits(blocksA, h);
                    int waysB = count_fits(blocksB, w);
                    ans += (waysA * waysB);
                }
            }
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();

    return 0;
}