#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int A=1100;
int N;
int f_l[A],f_r[A];
int h[A];


int main(){
    
	cin>>N;
	
	for(int i=1;i<=N;i++){
		cin>>h[i];
	}
	
	h[0]=0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<i;j++){
			if(h[i]>h[j]){
				f_l[i]=max(f_l[i],f_l[j]+1);
			}
		}
	}
	
	h[N+1]=0;
	for(int i=N;i>0;i--){
		for(int j=N+1;j>i;j--){
			if(h[i]>h[j]){
				f_r[i]=max(f_r[i],f_r[j]+1);
			}
		}
	}
	
	int result=0;
	
	for(int i=1;i<=N;i++){
		result=max(result,f_l[i]+f_r[i]-1);
	}
	
	cout<<result<<endl;
	
	return 0;	
}
