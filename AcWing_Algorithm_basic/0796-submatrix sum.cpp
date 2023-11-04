#include<iostream>

using namespace std;

const int N=1010;
int num[N][N],sum[N][N];
int n,m,q;
int x1,x2,y1,y2;

int main(){
    cin>>n>>m>>q;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>num[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+num[i][j];
        } 
    }
    
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        cout<<sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]<<endl;
    }
    return 0;
}
