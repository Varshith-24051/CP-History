#include <bits/stdc++.h>
using namespace std;

void solution(){
int n ;cin>>n;
vector<int> container(n);
for(int i = 0 ; i < n ; i++)cin>>container[i];
int element_min = INT_MAX;
if(!is_sorted(container.begin(),container.end())){
cout<<0<<endl;
return;
}
 for (int i = 0; i < n - 1; i++) {
        double diff = abs(container[i + 1] - container[i]);
        int val = ceil((diff + 1.0) / 2.0);  
        element_min = min(val, element_min);
    }

    cout << element_min << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--){
        solution();
    }
    return 0;
}