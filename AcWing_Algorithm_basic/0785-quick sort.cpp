#include<iostream>
#include<algorithm>

using namespace std;
const int N=100005;
int num[N];
int n;
int l=1,r;

void quickSort(int num[],int l,int r){
	if(l>=r) return;
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
	
	quickSort(num,l,j);
	quickSort(num,j+1,r);
}
			

int main(){
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	
	quickSort(num,l,r);
	for(int i=1;i<=n;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}

