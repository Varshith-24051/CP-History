#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void process_test_case() {
    ll target_n, element_count;
    cin >> target_n >> element_count;

    if (element_count % 2 != 0) {
        for (int i = 0; i < element_count; ++i) {
            cout << target_n << (i == element_count - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    ll best_first = target_n;
    ll best_second = 0;
    ll max_sum_found = target_n;

    int highest_bit = 0;
    for (int i = 30; i >= 0; i--) {
        if ((target_n >> i) & 1) {
            highest_bit = i;
            break;
        }
    }

    ll candidate_first = (1LL << highest_bit) - 1;
    ll candidate_second = target_n ^ candidate_first;

    if (candidate_first <= target_n && candidate_second <= target_n) {
        if (candidate_first + candidate_second > max_sum_found) {
            max_sum_found = candidate_first + candidate_second;
            best_first = candidate_first;
            best_second = candidate_second;
        }
    }

    for (int i = 0; i < element_count - 2; ++i) {
        cout << target_n << " ";
    }
    cout << best_first << " " << best_second << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        process_test_case();
    }
    return 0;
}