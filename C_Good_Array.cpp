#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    long long total_sum = 0;
    
    long long max1 = 0;
    long long max2 = 0; 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];

        if (a[i] > max1) {
            max2 = max1; 
            max1 = a[i]; 
        } else if (a[i] > max2) {
            max2 = a[i]; 
        }
    }

    vector<int> nice_indices;

    for (int i = 0; i < n; i++) {
        if (a[i] == max1) {
            if (total_sum - a[i] == max2 * 2) {
                nice_indices.push_back(i + 1); 
            }
        } 
        else {
            if (total_sum - a[i] == max1 * 2) {
                nice_indices.push_back(i + 1);
            }
        }
    }

    cout << nice_indices.size() << "\n";
    for (int i = 0; i < nice_indices.size(); i++) {
        cout << nice_indices[i] << " ";
    }
    cout << "\n";

    return 0;
}