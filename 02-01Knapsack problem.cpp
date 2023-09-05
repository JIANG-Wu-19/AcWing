#include<iostream>
#include<algorithm>

using namespace std;

const int n=1000;

int N,V;
int v[n],w[n];
int f[n][n];

int main(){
	cin>>N>>V;
	for(int i=1;i<=N;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=N;i++){
		for(int j=0;j<=V;j++){
			f[i][j]=f[i-1][j];
			if(j>=v[i]) f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
		}
	}
	cout<<f[N][V]<<endl;
	return 0;
}
