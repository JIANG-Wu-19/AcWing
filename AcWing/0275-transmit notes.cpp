#include<iostream>
#include<algorithm>

using namespace std;

const int N=60,K=2*N;

int v[N][N];
//����·��ͬʱ���У�f[k][x1][x1]���ߵ���k����ʱ��
//�����ߵĲ���һ����������һ��ʱ����������ȷ�� 
int f[K][N][N];

int getMax(int i,int j,int k){
	return max(max(f[k-1][i-1][j-1],f[k-1][i][j-1]),max(f[k-1][i-1][j],f[k-1][i][j]));
}

int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>v[i][j];
		}
	}
	
	
	for(int k=2;k<=m+n;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[k][i][j]=getMax(i,j,k)+v[i][k-i];
				if(i!=j) f[k][i][j]+=v[j][k-j];
			}
		}
	} 
	
	cout<<f[m+n][m][m]<<endl;
	
	
	return 0;
}

