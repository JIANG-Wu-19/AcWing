#include<iostream>
#include<algorithm>

using namespace std;

const int A=1005;
int N;
int x[A],sum[A]={0};


int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>x[i];
	}
	
	x[0]=0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<i;j++){
			if(x[i]>x[j]){
				sum[i]=max(sum[i],sum[j]+x[i]);
				//f_l[i]=max(f_l[i],f_[j]+1)
			}
		}
	}
	
	int result=0;
	for(int i=1;i<=N;i++){
		if(sum[i]>result){
			result=sum[i];
		}
	}
	
	cout<<result<<endl;
	
}
