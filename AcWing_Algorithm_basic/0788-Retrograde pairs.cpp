#include<iostream>

using namespace std;
typedef long long LL;

const int N=100010;
int num[N],tmp[N];
int n;

LL mergeSort(int l,int r){
	if(l>=r) return 0;
	int mid=l+r>>1;
	LL res=mergeSort(l,mid)+mergeSort(mid+1,r);
	
	int k=1,i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(num[i]<=num[j]) tmp[k++]=num[i++];
		else{
			tmp[k++]=num[j++];
			res+=mid-i+1;
		}
	}
	while(i<=mid) tmp[k++]=num[i++];
	while(j<=r) tmp[k++]=num[j++];
	
	for(int i=l,j=1;i<=r;i++,j++){
		num[i]=tmp[j];
	}
	return res;
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	
	cout<<mergeSort(1,n)<<endl;
}
