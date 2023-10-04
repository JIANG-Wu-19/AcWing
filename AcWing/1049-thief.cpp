#include<iostream>
#include<algorithm>

using namespace std;

const int N=100000;
int t,n;
int v[N],f[N];


int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		
		f[0]=0;
		f[1]=v[1];
		for(int i=2;i<=n;i++){
			f[i]=max(f[i-1],f[i-2]+v[i]);
		}
		
		cout<<f[n]<<endl;
		
		
	}
	
	return 0;
	
}
