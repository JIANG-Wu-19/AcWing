#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=100005;
int n; 
int v[N];
int f[N][2];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	
	for(int i=1;i<=n;i++){
		f[i][0]=f[i-1][0];
		f[i][0]=max(f[i][0],f[i-1][1]+v[i]);
		f[i][1]=max(f[i-1][1],f[i-2][0]-v[i]);
	}
	
	cout<<f[n][0]<<endl;
}

