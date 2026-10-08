#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = opt<int>(1);         
    int sum_n = opt<int>(2);      
    long long max_val = opt<long long>(3); 

    cout << t << "\n";

    vector<int> n_values = rnd.partition(t, sum_n, 1);

    for (int i = 0; i < t; i++) {
        int n = n_values[i];
        cout << n << "\n";

        for (int j = 0; j < n; j++) {
            long long a_i = rnd.next(-max_val, max_val);
            cout << a_i;
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}