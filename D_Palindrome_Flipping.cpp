#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef vector<pi> vpi;

vpi mapping(string S) {
    int n = S.size();
    vpi ans;

    while (true) {
        bool allTrue = true;
        for (char x : S) {
            if (x == '1') {
                allTrue = false;
                break;
            }
        }
        if (allTrue) break;

        int L = -1, R = -1;

       
        for (int i = 0; i < n - 1; i++) {
            if (S[i] == S[i+1]) {
                L = i;
                R = i + 1;

                while (R + 1 < n && S[R + 1] == S[i])
                    R++;

                break;
            }
        }

     
        if (L == -1) {
            L = 0;
            R = 2;
        }

        for (int i = L; i <= R; i++) {
            S[i] = '0' + '1' - S[i];
        }

        ans.push_back({L, R});
    }

    return ans;
}

void solution() {
    int N;
    string S, T;
    cin >> N;
    cin >> S >> T;

    vpi A = mapping(S);
    vpi B = mapping(T);

    reverse(B.begin(), B.end());

    for (auto &p : B) {
        A.push_back(p);
    }

    cout << A.size() << "\n";
    for (auto &p : A) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();

    return 0;
}
