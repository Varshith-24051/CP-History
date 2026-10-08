#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        char a[10][10];
        for (int i = 0; i < 10; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 10; j++) a[i][j] = s[j];
        }

        int total_score = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (a[i][j] == 'X') {
                    int d = max(abs(i - 4), abs(j - 4)); 
                    int cell_score = 5 - min(d, 4);      
                                       total_score += cell_score;
                }
            }
        }
        cout << total_score << endl;
    }
    return 0;
}
