#include<iostream>
#include<algorithm>

using namespace std;

const int N=1005,M=505,K=105;
int n,m,k;
int w[K],v[K],f[N][M];

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i]>>v[i];
	}
	
	f[0][0]=0;
	for(int i=1;i<=k;i++){
		for(int j=n;j>=w[i];j--){
			for(int a=m;a>=v[i];a--){
				f[j][a]=max(f[j][a],f[j-w[i]][a-v[i]]+1);
			}
		}
	}
	
	int res=-1,t;
	for(int i=0;i<=n;i++){
		for(int j=0;j<m;j++){
			if(f[i][j]>res||(res==f[i][j]&&j<t)){
				res=f[i][j];
				t=j;
			}
		}
	}
	
	cout<<res<<" "<<m-t<<endl;
	return 0;
}
