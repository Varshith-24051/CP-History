#include <bits/stdc++.h>
using namespace std;

void solution() {
    int w , h , a, b ; cin >> w >> h >> a>> b;
    int x , y , X , Y ; cin >> x >> y >> X >> Y ;

    int dist1 = abs(x+a - X);
    int dist2 = abs(y+b - Y);
    if(dist1==0||dist2==0) {
        cout << "Yes" << "\n";
        return;
    }
    if(x+a==X||y+b==Y) {
        cout << "Yes" << "\n";
    } else if(dist1<a|| dist2 < b) {
        cout << "No" << "\n";
    }
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