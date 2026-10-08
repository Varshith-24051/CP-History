#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n , s , x ; cin >> n >> s>>x;
    vector<int> a (n);
    for(int& x :a )cin >> x ; 

    int summ = accumulate(a.begin(),a.end(),0);
    if(summ <=s && (s-summ)%x==0)cout<< "YES"<<endl;
    else cout<<"NO"<<endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}