#include<bits/stdc++.h>
using namespace std;

const int N=10010;

int S[N][N];
int n,a,b;

int main(){
	memset(S,0,sizeof(S));
	cin>>n>>a>>b;
	
	while(n--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x2<0&&y2<0) continue;
		if(x1<0){
			x1=0;
		}
		if(y1<0){
			y1=0;
		}
		for(int i=x1;i<x2;i++){
			for(int j=y1;j<y2;j++){
				S[i][j]=1;
			}
		}
	}
	
	int res=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			res+=S[i][j];
		}
	}
	
	cout<<res<<endl;
	return 0;
}
			
	
