#include<iostream>
#include<algorithm>

using namespace std;

const int n=105;
int N;
int f_l[n],f_r[n];
int T[n];

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>T[i];
	}
	
	T[0]=0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<i;j++){
			if(T[i]>T[j]){
				f_l[i]=max(f_l[i],f_l[j]+1);
			}
		}
	}
	
	T[N+1]=0;
	for(int i=N;i>=1;i--){
		for(int j=N+1;j>i;j--){
			if(T[i]>T[j]){
				f_r[i]=max(f_r[i],f_r[j]+1);
			}
		}
	}
	
	int result=0;
	for(int i=1;i<=N;i++){
		result=max(result,f_l[i]+f_r[i]-1);
	}
	
	cout<<N-result<<endl;
	
}
