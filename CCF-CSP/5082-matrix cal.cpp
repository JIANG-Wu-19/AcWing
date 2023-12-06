#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=10010,D=25;
ll n,d;

ll Q[N][D];
ll KT[D][N];
ll V[N][D];
ll W[N];

int main(){
	cin>>n>>d;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			cin>>Q[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			cin>>KT[j][i];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			cin>>V[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		cin>>W[i];
	}
	
	ll tmp1[D][D];
	memset(tmp1, 0, sizeof(tmp1));
	for(int i=1;i<=d;i++){
		for(int j=1;j<=d;j++){
			for(int k=1;k<=n;k++){
				tmp1[i][j]+=KT[i][k]*V[k][j];
			}
		}
	}
	
	ll tmp2[N][D];
	memset(tmp2, 0, sizeof(tmp2));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			for(int k=1;k<=d;k++){
				tmp2[i][j]+=Q[i][k]*tmp1[k][j];
			}
		}
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			cout<<tmp2[i][j]*W[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
	
}
