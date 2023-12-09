#include<bits/stdc++.h>

using namespace std;
int C[25]={1};
int a[25];
int n,m;

int main(){	
	
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		C[i]=C[i-1]*a[i];
	}
	
	for(int i=1;i<=n;i++){
		cout<<(m%C[i]-m%C[i-1])/C[i-1]<<" ";
	}
	
	return 0;
}
