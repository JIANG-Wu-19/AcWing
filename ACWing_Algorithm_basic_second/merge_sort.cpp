#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n;
int num[N],tmp[N];

void merge_sort(int num[],int l,int r){
    //�ݹ���ֹ����
    if(l>=r) return;
    
	//1.��
	int mid=l+r>>1;
	
	//2.�ݹ�����
	merge_sort(num,l,mid);
	merge_sort(num,mid+1,r);
	
	//3.�鲢
	for(int i=l;i<=r;i++){
		tmp[i]=num[i];
	} 

	//i����������,j���������� ,k���ڶ�λ���մ��� 
	int i,j,k;
	for(i=l,j=mid+1,k=i;i<=mid&&j<=r;k++){
		if(tmp[i]<tmp[j]){
			num[k]=tmp[i++];
		}else{
			num[k]=tmp[j++];
		}
	}
	
	//��ʣ�ಿ��ȫ���ƽ���
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
