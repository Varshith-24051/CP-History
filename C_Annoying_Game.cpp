#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// A constant for a very small number (since a_i can be large negative)
const long long INF = -3e18; 

// Function to calculate the Maximum Non-Empty Subarray Sum (Kadane's Algorithm)
long long max_subarray_sum(const vector<long long>& arr) {
    if (arr.empty()) return 0;

    // Use a large negative number for initialization to handle all negative elements
    long long max_so_far = INF; 
    long long current_max = 0;

    // Kadane's implementation must be careful to handle all negative arrays.
    // We check if the largest single element is the result.
    long long max_single = arr[0];
    for(long long x : arr) {
        max_single = max(max_single, x);
        current_max = current_max + x;
        if (current_max < 0) {
            current_max = 0;
        }
        max_so_far = max(max_so_far, current_max);
    }
    
    // If all sums are non-positive, the result is the largest single element.
    if (max_so_far == 0) return max_single;
    
    return max_so_far;
}

// O(N) solution using pre-calculation
void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) return;
    }

    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> b[i])) return;
    }

    // Step 1: Handle the case where k is even
    if (k % 2 == 0) {
        cout << max_subarray_sum(a) << "\n";
        return;
    }

    // --- k is odd (O(N) solution required) ---

    // 1. Calculate Max Prefix Sums (MPL) ending at i
    vector<long long> mpl(n);
    mpl[0] = a[0];
    for (int i = 1; i < n; ++i) {
        mpl[i] = max(a[i], a[i] + mpl[i-1]);
    }

    // 2. Calculate Max Suffix Sums (MPR) starting at i
    vector<long long> mpr(n);
    mpr[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; --i) {
        mpr[i] = max(a[i], a[i] + mpr[i+1]);
    }
    
    // 3. Initialize max_final_score with the best score from the initial array (just in case the max subarray doesn't include the modified element).
    // Note: Since max_subarray_sum finds the overall max, we can initialize using it.
    long long max_final_score = max_subarray_sum(a);

    // 4. Iterate over all n scenarios (where a[x] receives the net gain b[x])
    for (int x = 0; x < n; ++x) {
        // Max subarray sum that includes index x in the initial array (S_max_include(x))
        // This is the max prefix ending at x PLUS the max suffix starting at x,
        // but since a[x] is included in both MPL[x] and MPR[x], we subtract it once.
        long long s_max_include_x = mpl[x] + mpr[x] - a[x];
        
        // The new score if a[x] is increased by b[x] (the final net gain)
        long long current_score = s_max_include_x + b[x];
        
        max_final_score = max(max_final_score, current_score);
    }

    cout << max_final_score << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}