#include<bits/stdc++.h>

using namespace std;

//dp[i][j]表示前i张邮票组成总值为j所需的最小邮票数
//dp[i][j]=min(dp[i-1][j],dp[i-1][j-value[i]]+1)

const int N=105;

int main()
{
    int m,n;
    while(cin>>m>>n){
        int dp[N][N];
        int value[N];
        for(int i=1;i<=n;i++){
            cin>>value[i];
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j]=1000000;
            }
        }

        dp[0][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j<value[i]){
                    dp[i][j]=dp[i-1][j];
                    continue;
                }
                else{
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-value[i]]+1);
                }
            }
        }

        if(dp[n][m]==1000000)
            cout<<0<<endl;
        else
            cout<<dp[n][m]<<endl;
    }
}
