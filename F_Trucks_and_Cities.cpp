#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct truck{
    int start , end , mult;
};
void solution(){
    int n , m ; cin >> n >> m ;

    vector<int> a(n);
    vector<vector<truck>> trucks(n+1);
    for(int i = 0 ; i < n ;i++)cin >> a[i]; 
    for(int i = 0 ; i < m ;i++){
        int s  , f ,c ,  r;
        cin>> s>>f>>c>>r;
        s--;f--;
        trucks[min(r,n)].push_back({s,f,c});
    }
    vector<int> prevdp(n*n,0);
    vector<int>currdp(n*n,0);
    for(int i = 0; i < n;i++ ){
        for(int j= i ; j<n;j++){
            currdp[i*n +j ]= a[j]-a[i];
        }
    }
    int maxtank = LLONG_MIN;

    auto process = [&](int currk){
        for(auto& t : trucks[currk]){
            maxtank = max(maxtank , 1LL*currdp[t.start*n + t.end]*t.mult);
        }
    };

    process(0);
    for(int k = 1 ; k <= n;k++){
        for(int i = 0 ; i < n ; i++){
            int split = i ; 

            for(int j = i ; j < n ;j++){
                if(i ==j ){
                    prevdp[i*n +j]= 0;
                    continue; 
                }
                while(split + 1 < j && currdp[i*n+split +1]<=a[j] - a[split +1]){
                    split++;
                }//simple to movee da 

                int curr_best = max(currdp[i*n + split] , a[j] - a[split]);
                if(split + 1 < j){
                    int next_best = max (currdp[i*n+ split+1 ], a[j]- a[split+1]);
                    curr_best = min ( curr_best , next_best);
                }
                prevdp[i*n + j] = curr_best;
            }
        }
        prevdp.swap(currdp);
        process(k);
    }
cout<<maxtank<<endl;
return;


}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //int t = 1;
    //cin >> t;
    //while (t--) 
    solution();
    return 0;
}