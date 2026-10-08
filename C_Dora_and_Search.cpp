#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ; cin >> n ; 
    vector<int> a(n); 
    for(int & x : a ) cin >> x ; 

    int left = 0 , right = n-1 ; 
    int min = 1 , max = n ;
    
    while(left<right){
        if(a[left]==max ){
            left++;
            max--;
        }
        if(a[left]==min){
            left++;
            min++;
        }
        if(a[right]==max ){
            right--;
            max--;
        }
        if(a[right]==min){
            right--;
            min++;
        }
        if((a[left]!=max && a[left]!=min) && (a[right]!=max && a[right]!=min)){
            cout<< left+1<<" "<<right+1<<endl;
            return;
        }
    }
    cout<<-1<<endl; 
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