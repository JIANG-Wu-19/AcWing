#include<iostream>
#include<algorithm>

using namespace std;

const int N=20,M=3005;
int v[N];
long long f[N][M];
int n,m;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k*v[i]<=j;k++){
				f[i][j]+=f[i-1][j-k*v[i]];
			}
		}
	}
	
	cout<<f[n][m]<<endl;
	return 0;
}
