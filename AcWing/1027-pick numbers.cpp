#include<iostream>
#include<algorithm>

using namespace std;

const int n=15,K=2*n;

int v[n][n];
//两次路径同时进行，f[k][x1][x1]，走到第k步的时候
//两者走的步数一定、横坐标一定时，绝对坐标确定 
int f[K][n][n];

int getMax(int i,int j,int k){
	return max(max(f[k-1][i-1][j-1],f[k-1][i][j-1]),max(f[k-1][i-1][j],f[k-1][i][j]));
}

int main(){
	int N;
	cin>>N;
	
	int a,b,c;
	while(cin>>a>>b>>c,a||b||c) v[a][b]=c;
	
	for(int k=2;k<=2*N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(k-i<=0||k-i>N||k-j<=0||k-j>N)
					continue;
				f[k][i][j]=getMax(i,j,k)+v[i][k-i];
				if(i!=j) f[k][i][j]+=v[j][k-j];
			}
		}
	} 
	
	cout<<f[2*N][N][N]<<endl;
	
	
	return 0;
}

