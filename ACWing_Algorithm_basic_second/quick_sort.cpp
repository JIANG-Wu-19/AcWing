#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n;
int num[N];

void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    
    int i=l-1,j=r+1,x=q[l+r>>1];
    
    while(i<j){
        do{
            i++;
        }while(q[i]<x);
        do{
            j--;
        }while(q[j]>x);
        if(i<j){
            swap(q[i],q[j]);
        }
    }
    
    quick_sort(q,l,j),quick_sort(q,j+1,r);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    
    quick_sort(num,1,n);
    
    for(int i=1;i<=n;i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

