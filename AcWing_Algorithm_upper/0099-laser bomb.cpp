#include<iostream>
#include<algorithm>

using namespace std;
const int N=5005;
int mp[N][N];
int n,r;

int main(){
	cin>>n>>r;
	r=min(r,5001);
	for(int i=0;i<n;i++){
		int x,y,w;
		cin>>x>>y>>w;
		mp[++x][++y]+=w;
	}
	
	for(int i=1;i<=5001;i++){
		for(int j=1;j<=5001;j++){
			mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
		}
	}
	
	int res=0;
	
	for(int i=r;i<=5001;i++){
		for(int j=r;j<=5001;j++){
			res=max(res,mp[i][j]-(mp[i-r][j]+mp[i][j-r]-mp[i-r][j-r]));
		}
	}
	
	cout<<res<<endl;
	return 0;
}
