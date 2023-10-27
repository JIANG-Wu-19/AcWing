#include<iostream>

using namespace std;

const int N=1000010;
int num[N],tmp[N];
int n;

void mergeSort(int num[],int l,int r){
    if(l>=r) return;
    int mid=l+r>>1;
    
    mergeSort(num,l,mid);
    mergeSort(num,mid+1,r);
    
    int k=1,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(num[i]<=num[j]) tmp[k++]=num[i++];
        else tmp[k++]=num[j++];
    }
    while(i<=mid) tmp[k++]=num[i++];
    while(j<=r) tmp[k++]=num[j++];
    
    for(int i=l,j=1;i<=r;i++,j++){
        num[i]=tmp[j];
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    
    mergeSort(num,1,n);
    
    for(int i=1;i<=n;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
