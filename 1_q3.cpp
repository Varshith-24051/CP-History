#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number; 
    cin >> number;
    int counter =0 ; 
    for(int i = 1 ; i*i<number ;i++){
        if(number%i==0)counter++;
    }
    cout<<counter+1<<endl ; 
    return 0;
}