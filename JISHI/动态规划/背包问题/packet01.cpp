#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int c,n;
int dp[N];
int weight[N],value[N];

int main()
{
    while(cin>>c>>n){
        for(int i=0;i<n;i++){
            cin>>weight[i]>>value[i];
        }

        for(int i=0;i<c;i++){
            dp[i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=c;j>=w[i];j--){
                dp[j]=max(dp[j],dp[i-w[j]]+v[i]);
            }
        }

        cout<<dp[c]<<endl;
    }
}
