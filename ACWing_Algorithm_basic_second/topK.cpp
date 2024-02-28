#include<iostream>
#include<algorithm>

using namespace std;
const int N=100005;
int num[N];
int n,k;

int findK(int num[],int l,int r,int k){
    //终止条件
    if(l>=r) return num[l];
    
    //进行第一部划分
    int i=l-1,j=r+1,pivot=num[l+r>>1];
    
    while(i<j){
        do{
            i++;
        }while(num[i]<pivot);
        do{
            j--;   
        }while(num[j]>pivot);
        
        if(i<j) swap(num[i],num[j]);
    }
    
    if(j>=k){
        findK(num,l,j,k);
    }else{
        findK(num,j+1,r,k);
    }
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	cout<<findK(num,1,n,k)<<endl;
	
	return 0;
}
