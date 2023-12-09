#include<bits/stdc++.h>

using namespace std;

int Q[8][8];
int n,T;
int s[64];
int M[8][8];
int res1[8][8];

double alpha(int u){
	if(u) return 1.0;
	else return sqrt(1/2.0);
}

int main(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>Q[i][j];
		}
	}
	
	cin>>n>>T;
	
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	int cnt=0;
	int a=0;
	int b=0;
	bool flag=true;
	
	while(a!=8||b!=8){
		if(a<8&&b<8){
			if(cnt==n) break;
			M[a][b]=s[cnt++];
		}
		if(flag){
			a-=1;
			b+=1;
		}else{
			a+=1;
			b-=1;
		}
		
		if(a<0){
			a=0;
			flag=!flag;
		}
		
		if(b<0){
			b=0;
			flag=!flag;
		}
	}
	
	if(T==0){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout<<M[i][j]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			M[i][j]*=Q[i][j];
		}
	}
	
	if(T==1){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout<<M[i][j]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	
	return 0;
		
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			double res=0;
			for(int u=0;u<8;u++){
				for(int v=0;v<8;v++){
					res+=alpha(u)*alpha(v)*cos(acos(-1)*(i+1/2.0)*u/8.0)*cos(acos(-1)*(j+1/2.0)*v/8.0)*M[u][v];
				}
			}
			res/=4.0;
			res+=128;
			
			if(res-(int)res>=0.5) res+=1;
			
			if(res>255) cout<<"255 ";
			else if(res<0) cout<<"0 ";
			else cout<<(int)res<<" ";
		}
		cout<<endl;
	}
	
	return 0;
			
			
		
}
