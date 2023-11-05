#include<iostream>

using namespace std;

const int N=100010;
int n,m;
int num[N],sub[N];
int l,r,c;


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        sub[i]=num[i]-num[i-1];
    }
    while(m--){
        cin>>l>>r>>c;
        sub[l]+=c;
        sub[r+1]-=c;
    }
    for(int i=1;i<=n;i++){
        num[i]=num[i-1]+sub[i];
        cout<<num[i]<<' ';
    }
    cout<<endl;
    return 0;
}
