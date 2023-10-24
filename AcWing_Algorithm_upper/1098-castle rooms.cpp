#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int,int> PII;
const int N=50;

int g[N][N];
int dist[N][N];

int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

int n,m;

int bfs(int x,int y){
	dist[x][y]=0;
	queue<PII> q;
	q.push({x,y});
	
	int num=0;
	while(q.size()){
		PII p=q.front();
		q.pop();
		num++;
		
		int a=p.first,b=p.second;
		for(int i=0;i<4;i++){
			if(!(g[a][b]>>i&1)){
				int c=a+dx[i],d=b+dy[i];
				if(dist[c][d]==-1){
					dist[c][d]=dist[a][b]+1;
					q.push({c,d});
				}
			}
		}
	}
	return num;
}


int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	
	int res=0,maxv=0;
	memset(dist,-1,sizeof dist);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dist[i][j]==-1){
				res++;
				maxv=max(maxv,bfs(i,j));
			}
		}
	}
	cout<<res<<endl;
	cout<<maxv<<endl;
	
	return 0;
}

