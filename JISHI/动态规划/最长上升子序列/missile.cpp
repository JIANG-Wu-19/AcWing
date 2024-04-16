#include<bits/stdc++.h>

using namespace std;

const int N=30;

int missile[N];
int dp[N];

int main()
{
    int k;
    while(cin>>k){
        for(int i=k;i>=1;i--){
            cin>>missile[i];
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            dp[i]=1;
            for(int j=1;j<i;j++){
                if(missile[i]>=missile[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }

        cout<<ans<<endl;
    }
}
