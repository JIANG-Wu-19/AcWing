#include<iostream>
#include<algorithm>

using namespace std;

const int N=5,M=1005;
int f[N][M];
int v[N]={0,10,20,50,100};
int n;

int main(){
	cin>>n;
	f[0][0]=1;
	
	for(int i=1;i<=4;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;v[i]*k<=j;k++){
				f[i][j]+=f[i-1][j-v[i]*k];
			}
		}
	}
	
	cout<<f[4][n]<<endl;
	return 0;
}

