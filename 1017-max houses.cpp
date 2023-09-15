#include<iostream>
#include<algorithm>

using namespace std;

const int A=105;
int K,N,n;
int h[A];
int f_l[A],f_r[A];


int main(){
	cin>>K;
	while(K--){
		memset(f_l, 0, sizeof f_l);
        memset(f_r, 0, sizeof f_r);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>h[i];
		}
		
		h[0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				if(h[i]>h[j]){
					f_l[i]=max(f_l[i],f_l[j]+1);
				}
			}
		}
		
		h[n+1]=0;	
		for(int i=n;i>0;i--){
			for(int j=n+1;j>i;j--){
				if(h[i]>h[j]){
					f_r[i]=max(f_r[i],f_r[j]+1);
				}
			}
		}
		
		int result=0;
		
		for(int i=1;i<=n;i++){
			result=max(max(result,f_l[i]),max(result,f_r[i]));
		}
		
		cout<<result<<endl;
				
	}
	
	return 0;
}
