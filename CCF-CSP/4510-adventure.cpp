#include<bits/stdc++.h>

using namespace std;

int n,L,S,k=0;
int x[1005],y[1005];
int B[55][55]={0};


int main(){
	cin>>n>>L>>S;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	
	for(int i=S;i>=0;i--){
		for(int j=0;j<=S;j++){
			cin>>B[i][j];
			k+=B[i][j];
		}
	}
	
	int cnt=0;
	
	for(int i=1;i<=n;i++){
		int px=x[i],py=y[i];
		if(px+S<=L&&py+S<=L){
			int num=0;
			for(int j=1;j<=n;j++){
				if(x[j]>=px&&y[j]>=py&&x[j]<=px+S&&y[j]<=py+S){
					if(!B[x[j]-px][y[j]-py]){
						num=0;
						break;
					}
					num++;
				}
			}
			if(num==k) cnt++;
		}
	}
	
	cout<<cnt<<endl;
		
}
