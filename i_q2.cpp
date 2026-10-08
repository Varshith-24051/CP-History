#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    int count = 0;
    vector<int> line(N);

    for (int i = 0; i < N; i++)
        cin >> line[i];

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((line[i] + line[j]) % D == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
