#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

int n,m;
char land[N][N];

void dfs(int x,int y){
	land[x][y]='.';
	for(int i=0;i<8;i++){
		if(land[x+dx[i]][y+dy[i]]=='W'){
			dfs(x+dx[i],y+dy[i]);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>land[i][j];
		}
	}
	
	int res=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(land[i][j]=='W'){
				dfs(i,j);
				res++;
			}
		}
	}
	
	cout<<res<<endl;
	return 0;
}
