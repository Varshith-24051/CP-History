#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10000, "t");
    inf.readEoln();

    int sum_n = 0;

    for (int i = 0; i < t; i++) {
        int n = inf.readInt(1, 200000, "n");
        inf.readEoln();
        
        sum_n += n;

        for (int j = 0; j < n; j++) {
            inf.readInt(-1000000000, 1000000000, "a_i");
            
            if (j < n - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }

    ensuref(sum_n <= 200000, "actual sum: %d)", sum_n);

    inf.readEof();

    return 0;
}