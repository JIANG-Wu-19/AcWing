#include<iostream>
#include<algorithm>

using namespace std;

const int n=105;
int v[n][n],f[n][n];
int N;

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>v[i][j];
		}
	}
	
	for(int j=1;j<=N;j++){
		f[1][j]=f[1][j-1]+v[1][j];
	}
	
	for(int i=1;i<=N;i++){
		f[i][1]=f[i-1][1]+v[i][1];
	}
	
	for(int i=2;i<=N;i++){
		for(int j=2;j<=N;j++){
			f[i][j]=min(f[i-1][j],f[i][j-1])+v[i][j];
		}
	}
	cout<<f[N][N]<<endl;
	return 0;
}

