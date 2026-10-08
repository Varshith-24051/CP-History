#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Elf {
    long long a;
    int id;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Elf> elves(n);
    for (int i = 0; i < n; i++) {
        cin >> elves[i].a;
        elves[i].id = i + 1;
    }

    sort(elves.begin(), elves.end(), [](const Elf &x, const Elf &y) {
        return x.a < y.a;
    });

    // Special Case: m = 0
    if (m == 0) {
        long long sum_small = 0;
        for (int i = 0; i < n - 1; i++) sum_small += elves[i].a;
        if (sum_small <= elves[n - 1].a) {
            cout << -1 << "\n";
        } else {
            cout << n - 1 << "\n";
            for (int i = 0; i < n - 1; i++) 
                cout << elves[i].id << " " << elves[n - 1].id << "\n";
        }
        return;
    }

    // To have m survivors, we need n-m elves to die.
    // If m > 1, all survivors must attack. This requires enough victims.
    // The most efficient construction:
    // 1. n-m small elves attack the King (elves[n-1]) and die.
    // 2. The other m-1 survivors each attack the King.
    
    // To survive as the King:
    // Health = a[n-1] - (sum of attacks from n-m small elves) - (sum of attacks from m-1 survivors)
    // BUT WAIT: If m-1 survivors attack the King, they must be smaller than the King to die,
    // or the King must be smaller to die. 
    // Actually, if a survivor (x) attacks the King (y), and a_x < a_y, x dies. 
    // We want the m-1 survivors to LIVE. So they must be the targets or attack smaller elves.

    // Correct Construction for m >= 1:
    // 1. Let the King (elves[n-1]) attack n-m small elves one by one. 
    //    King lives, small elves die. King has now "attacked".
    // 2. Now we have m survivors. If m > 1, the other m-1 survivors also need to attack.
    //    This is only possible if they had small elves to kill.
    
    if (n - m < m) { // We need at least m small elves for the m survivors to kill
        if (m == 1) { // Special case: m=1 survivor doesn't have to attack
            long long damage = 0;
            for(int i=0; i<n-1; i++) damage += elves[i].a;
            if (damage >= elves[n-1].a) cout << -1 << "\n";
            else {
                cout << n-1 << "\n";
                for(int i=0; i<n-1; i++) cout << elves[i].id << " " << elves[n-1].id << "\n";
            }
        } else {
            cout << -1 << "\n";
        }
        return;
    }

    // General case for m > 1: 
    // Each of the m survivors kills one small elf.
    // Any remaining small elves attack the King.
    long long damage_to_king = 0;
    for (int i = m; i < n - m + (m-1); i++) { /* complex logic simplified below */ }

    // Let's use the simplest working construction:
    // Elves 0...n-m-1 are victims. Elves n-m...n-1 are survivors.
    // Survivors i (n-m...n-1) attack victims i-(n-m). 
    // This works if a[survivor] > a[victim].
    
    cout << n - m << "\n";
    for (int i = 0; i < n - m; i++) {
        // Elf (n-m-i) attacks Elf i.
        // As long as the attacker is larger, the victim dies and attacker lives.
        cout << elves[n - 1 - (i % m)].id << " " << elves[i].id << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}