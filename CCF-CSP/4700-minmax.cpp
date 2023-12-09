#include<bits/stdc++.h>
#include<algorithm>


using namespace std;
const int N=3e5+10;

int n,x;
int f[N];

int main(){
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	cin>>n>>x;
	
	while(n--){
		int v,w;
		cin>>v;
		w=v;
		
		for(int j=x;j>=0;j--){
			f[j]=min(f[j],f[max(0,j-v)]+w);
		}
		
	}
	
	cout<<f[x]<<endl;
	return 0;	
}
