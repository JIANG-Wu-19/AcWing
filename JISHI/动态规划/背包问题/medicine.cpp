#include<bits/stdc++.h>

using namespace std;

const int N=1005;

int weight[N],value[N];
int dp[N];

int main()
{
    int t,m;
    while(cin>>t>>m){
        for(int i=0;i<m;i++){
            cin>>weight[i]>>value[i];
        }
        for(int i=0;i<=t;i++){
            dp[i]=0;
        }

        for(int i=0;i<m;i++){
            for(int j=t;j>=weight[i];j--){
                dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }

        cout<<dp[t]<<endl;
    }
}
