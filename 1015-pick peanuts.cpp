#include<iostream>
#include<algorithm>
using namespace std;

const int N=105;
int v[N][N],f[N][N];
int T,R,C;

int main(){
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>R>>C;
		for(int j=1;j<=R;j++){
			for(int k=1;k<=C;k++){
				cin>>v[j][k];
			}
		}
		
		for(int j=1;j<=R;j++){
			for(int k=1;k<=C;k++){
				f[j][k]=max(f[j-1][k],f[j][k-1])+v[j][k];
			}
		}
		cout<<f[R][C]<<endl;
	}
	
	return 0;
}


