#include<bits/stdc++.h>

using namespace std;
const int N=100010;

int n,m,k,maxday=0;
int same[N];

int main(){
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++){
		int t,c;
		cin>>t>>c;
		same[t]+=c;
		maxday=max(maxday,t);
	}
	
	for(int i=maxday;i>=k;i--){
		if(m<same[i]){
			cout<<i<<endl;
			return 0;
		}
		m-=same[i];
		same[i-1]+=same[i];
	}
	
	cout<<k<<endl;
	return 0;
	
}
