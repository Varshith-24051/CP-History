#include <bits/stdc++.h>
using namespace std;

void solution(){
    long long n; 
    cin >> n;

    long long a = n * n;

    long long sum1 = 0;
if(n ==0||n==1){
    cout<< n<< endl; 
    return;
}
if(n==2){
        sum1 = max(sum1,
        (a) +
        (a - 1) +
        (a - n )
    );
    cout<< sum1<<endl;
    return ;
}
    sum1 = max(sum1,
        (a - n - 1) +
        (a - n) +
        (a - 1) +
        (a - n - 2) +
        (a - 2*n - 1)
    );

    sum1 = max(sum1,
        (a - 1) +
        (a) +
        (a - 2) +
        (a - n - 1)
    );


    cout << sum1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) solution();
    return 0;
}
