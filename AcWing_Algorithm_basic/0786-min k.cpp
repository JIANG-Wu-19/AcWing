#include<iostream>
#include<algorithm>

using namespace std;
const int N=100005;
int num[N];
int n,k;

int quickSort(int num[],int l,int r,int k){
	if(l>=r) return num[l];
	int i=l-1,j=r+1,x=num[l+r>>1];
	while(i<j){
		do{
			i++;
		}while(num[i]<x);
		
		do{
			j--;
		}while(num[j]>x);
		if(i<j) swap(num[i],num[j]);
	}
	if(j-l+1>=k) return quickSort(num,l,j,k);
	else return quickSort(num,j+1,r,k-(j-l+1));
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	
	cout<<quickSort(num,1,n,k)<<endl;
	return 0;
}
