#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> score;
    for (int i = 0; i < n; i++) {
        string team;
        cin >> team;
        score[team]++;
    }

    // find team with max goals
    string winner;
    int maxGoals = -1;
    for (auto &p : score) {
        if (p.second > maxGoals) {
            maxGoals = p.second;
            winner = p.first;
        }
    }

    cout << winner << "\n";
    return 0;
}
