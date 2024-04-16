#include <bits/stdc++.h>
using namespace std;

const int N=25;
int dp[N];

int main() {
    for(int i=1;i<N;i++){
        if(i==1||i==2){
            dp[i]=i;
        }
        else{
            dp[i]=dp[i-1]+dp[i-2];
        }
    }
    int n;
    while(cin>>n){
        cout<<dp[n]<<endl;
    }
    return 0;
}
