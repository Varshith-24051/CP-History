#include <bits/stdc++.h>
using namespace std;
void answer(){
    int sizee =0 ; 
    cin>>sizee;
    long long summ = 0 ; 

    vector<int> v(sizee);
    for(int i = 0; i< sizee ;i++){
        cin>>v[i];
        summ+=v[i];
    }
    int l = 0 , r=sizee-1;
    double answer = 0 ; 
    while(l<=r){
        int avg = r-l+1;
        answer = max<double> ( answer , (double)summ/avg);
        if (v[l]<v[r]){
            summ-=v[l];
            l++;
        }
        else{
            summ-=v[r];
            r--;
        }
    }
    cout<<ceil(answer)<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0; 
    cin>> n ; 
while( n--){
    answer();
}
    return 0;
}