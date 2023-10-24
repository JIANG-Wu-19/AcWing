#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N=3e5+10;

int n,m;
ll s[N],q[N];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]+=s[i-1];
	}
	
	ll res=-1e18;
	
	int hh=0,tt=0;
	q[0]=0;
	for(int i=1;i<=n;i++){
		while(hh<=tt&&i-q[hh]>m) hh++;
		res=max(res,s[i]-s[q[hh]]);
		while(hh<=tt&&s[q[tt]]>=s[i]) tt--;
		q[++tt]=i;
	}
	cout<<res<<endl;
	return 0;
}
