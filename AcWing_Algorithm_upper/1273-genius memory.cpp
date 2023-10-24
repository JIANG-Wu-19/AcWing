#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int N=200010,M=18;
int a[N];
int n,m;
int f[N][M];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int j=0;j<M;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			if(!j) f[i][j]=a[i];
			else f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		int len=r-l+1;
		int k=log(len)/log(2);
		cout<<max(f[l][k],f[r-(1<<k)+1][k])<<endl;
	}
	return 0;
}
