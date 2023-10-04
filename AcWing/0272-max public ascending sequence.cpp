#include<iostream>
#include<algorithm>

using namespace std;

const int A=3005;

int N;
int a[A],b[A];
int f[A][A];

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	for(int i=1;i<=N;i++){
		cin>>b[i];
	}
	
	for(int i=1;i<=N;i++){
		int maxv=1;
		for(int j=1;j<=N;j++){
			f[i][j]=f[i-1][j];
			if(a[i]==b[j]){
				f[i][j]=max(f[i][j],maxv);
			}
			if(a[i]>b[j]){
				maxv=max(maxv,f[i-1][j]+1);
			}
		}
	}
	
	int result=0;
	for(int i=1;i<=N;i++){
		result=max(result,f[N][i]);
	}
	
	cout<<result<<endl;
	return 0;
}


