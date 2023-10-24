#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const int N=5050;

int n,S;
ll st[N],sc[N];
ll f[N];

int main(){
	cin>>n>>S;
	for(int i=1;i<=n;i++){
		cin>>st[i]>>sc[i];
		st[i]+=st[i-1];
		sc[i]+=sc[i-1];
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			f[i]=min(f[i],f[j]+st[i]*(sc[i]-sc[j])+S*(sc[n]-sc[j]));
		}
	}
	cout<<f[n]<<endl;
	return 0;
}


