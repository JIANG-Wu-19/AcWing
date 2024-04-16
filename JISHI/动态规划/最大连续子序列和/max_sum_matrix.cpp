#include<bits/stdc++.h>

using namespace std;

const int N=105;

//sum[i][j] is the sum of (1,1)-(i,j)

int num[N][N]={0};
int sum[N][N]={0};
int dp[N];

void init(int n)
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+num[i][j];
        }
    }
}


int main()
{
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>num[i][j];
            }
        }
        long long maxmatrix=-1e18;
        for(int k1=1;k1<=n;k1++){
            for(int k2=k1;k2<=n;k2++){
                for(int i=1;i<=n;i++){
                    ll tmp=sum[k2][i]-sum[k1-1][i];
                    dp[i]=max(dp[i-1]+tmp,tmp);
                    maxmatrix=max(maxmatrix,dp[i]);
                }
            }
        }
        cout<<maxmatrix<<endl;
        return 0;
    }


}
