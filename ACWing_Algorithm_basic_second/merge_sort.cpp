#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n;
int num[N],tmp[N];

void merge_sort(int num[],int l,int r){
    //递归终止条件
    if(l>=r) return;
    
	//1.分
	int mid=l+r>>1;
	
	//2.递归排序
	merge_sort(num,l,mid);
	merge_sort(num,mid+1,r);
	
	//3.归并
	for(int i=l;i<=r;i++){
		tmp[i]=num[i];
	} 

	//i在左子序列,j在右子序列 ,k用于定位最终次序 
	int i,j,k;
	for(i=l,j=mid+1,k=i;i<=mid&&j<=r;k++){
		if(tmp[i]<tmp[j]){
			num[k]=tmp[i++];
		}else{
			num[k]=tmp[j++];
		}
	}
	
	//将剩余部分全复制进表
	while(i<=mid)  num[k++]=tmp[i++];
	while(j<=r) num[k++]=tmp[j++];
}

int main(){
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	
	merge_sort(num,1,n);
	
	for(int i=1;i<=n;i++){
		cout<<num[i]<<" ";
	}
	
	cout<<endl;
	
	return 0;
	
}
