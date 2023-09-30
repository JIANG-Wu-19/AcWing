#include<iostream>
#include<algorithm>

using namespace std;

const int N=1005;
int t[N],v[N];
int f[N][N];
int T,M;

int main(){
	cin>>T>>M;
	
	for(int i=1;i<=M;i++){
		cin>>t[i]>>v[i];
	}
	
	for(int i=1;i<=M;i++){
		for(int j=0;j<=T;j++){
			f[i][j]=f[i-1][j];
			if(j>=t[i]) f[i][j]=max(f[i-1][j],f[i-1][j-t[i]]+v[i]);
		}
	}
	
	cout<<f[M][T]<<endl;
	return 0;
}
