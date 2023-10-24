#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=100000,K=105;
int n,k;
int v[N];
int f[N][K][2];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	
	memset(f,-0x3f,sizeof f);
	f[0][0][0]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			f[i][j][0]=f[i-1][j][0];
			if(j){
				f[i][j][0]=max(f[i][j][0],f[i-1][j-1][1]+v[i]);
			}
			f[i][j][1]=max(f[i-1][j][1],f[i-1][j][0]-v[i]);
		}
	}
	
	int res=0;
	for(int i=0;i<=k;i++){
		res=max(res,f[n][i][0]);
	}
	
	cout<<res<<endl;
	
}

