#include<bits/stdc++.h>

using namespace std;


int t[105],p[105];
int n,m;
int e[105],l[105],e_end[105];

int main(){
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	
	for(int i=1;i<=m;i++){
		if(!p[i]) e[i]=1;
		else e[i]=e[p[i]]+t[p[i]];	
		e_end[i]=min(n+1,e[i]+t[i]-1);
		cout<<e[i]<<" ";
	}
	cout<<endl;
	
	for(int i=1;i<=m;i++){
		if(e_end[i]==n+1) return 0;
	}
	
	memset(l,0x3f,sizeof(l));
	for(int i=m;i>=1;i--){
		if(l[i]>n) l[i]=n+1-t[i];
		if(p[i]) l[p[i]]=min(l[p[i]],l[i]-t[p[i]]);
	}
	
	for(int i=1;i<=m;i++){
		cout<<l[i]<<" ";
	}		
	cout<<endl;
	return 0;
	
		
}
