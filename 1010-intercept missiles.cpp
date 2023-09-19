#include<iostream>
#include<algorithm>

using namespace std;

const int N=1005;
int h[N];
int f_r[N],f_l[N];
int n=1;

int main(){
	while(cin>>h[n]) n++;
	
	h[n+1]=0;
// 	for(int i=n;i>0;i--){
// 		for(int j=n+1;j>i;j--){
// 			if(h[i]>h[j]){
// 				f_r[i]=max(f_r[i],f_r[j]+1);
// 			}
// 		}
// 	}
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(h[i]<=h[j]){
                f_r[i]=max(f_r[i],f_r[j]+1);
            }
        }
    }
	
	h[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(h[i]>h[j]){
				f_l[i]=max(f_l[i],f_l[j]+1);
			}
		}
	}
				
	
	int result1=0,result2=0;
	for(int i=1;i<=n;i++){
		result1=max(result1,f_r[i]);
		result2=max(result2,f_l[i]);
	}
	
	cout<<result1<<endl;
	cout<<result2<<endl;
}

