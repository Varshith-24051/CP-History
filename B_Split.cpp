#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    // Read n, the subsequences p and q will have size n, total array size 2n.
    if (!(cin >> n)) return; 

    // The array a has 2n elements.
    int size_2n = 2 * n;
    map<int, int> counts; // Map to store the frequency of each element

    for (int i = 0; i < size_2n; ++i) {
        int a_i;
        if (!(cin >> a_i)) return;
        counts[a_i]++;
    }

    int odd_count_total = 0;  // |D_odd|: Number of distinct elements with an odd total frequency
    int even_count_total = 0; // |D_even|: Number of distinct elements with an even total frequency

    // 1. Calculate the theoretical maximum based only on frequency parity.
    for (auto const& [value, count] : counts) {
        if (count % 2 != 0) {
            odd_count_total++;
        } else {
            even_count_total++;
        }
    }
    
    // Theoretical maximum: |D_odd| * 1 + |D_even| * 2
    long long max_f_sum = (long long)odd_count_total + 2LL * even_count_total;

    // 2. Apply Penalty (Size Constraint Check)
    // The theoretical maximum is NOT achievable only in a few tight scenarios:

    if (odd_count_total == 0) {
        // SCENARIO A: All element counts (C_x) are EVEN.
        
        if (n % 2 != 0) {
            // A1: If n is ODD (e.g., Case 7: n=5, [9,9,9,7,7,7,9,7,7,7]).
            // A size-n (odd) subsequence 'p' requires an odd sum of counts: sum(C_x(p)) = n (odd).
            // Since all C_x are even, all splits require C_x(p) and C_x(q) to have the same parity.
            // Summing equally-paritied numbers (C_x(p)) always results in an EVEN sum.
            // The constraint is violated: it's impossible to make sum(C_x(p)) odd.
            // We must sacrifice the optimal contribution (2) of one element in D_even.
            if (even_count_total > 0) {
                max_f_sum -= 2;
            }
        } else {
            // A2: If n is EVEN (e.g., Case 4: n=2, [2,2,2,2]).
            // If there's ONLY ONE distinct element (even_count_total = 1), 
            // then C_x = 2n, and C_x(p) MUST be n (even).
            // This forces C_x(p) and C_x(q) to be even, so the max contribution is 0.
            if (even_count_total == 1) {
                // If the only count is 2n, max_f_sum = 2. It should be 0.
                max_f_sum = 0; 
            }
            // If even_count_total > 1 and n is even, the theoretical max is achievable.
        }
    }

    cout << max_f_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0; // Read number of test cases

    while (t--) {
        solve();
    }

    return 0;
}