#include<iostream>

using namespace std;

const int N=100010;
int num[N],sum[N]={0};
int n,m;
int l,r;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        sum[i]=sum[i-1]+num[i];
    }
    while(m--){
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    
    // while(m--){
    //     int res=0;
    //     cin>>l>>r;
    //     for(int i=l;i<=r;i++){
    //         res+=num[i];
    //     }
    //     cout<<res<<endl;
    // }
    return 0;
}
