#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,q,k;
int num[N];

int main(){
    cin>>n>>q;
    
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    
    for(int i=1;i<=q;i++){
        cin>>k;
        
        //找下限
        int l=0,r=n-1;
        while(l<r){
            int mid=l+r>>1;
            if(num[mid]<k) l=mid+1;
            else r=mid;
        }
        if(num[l]!=k){
            cout<<"-1 -1"<<endl;
            continue;
        }
        
        //找上限 
        int l1=l,r1=n;
        while(l1+1<r1){
            int mid=l1+r1>>1;
            if(num[mid]<=k) l1=mid;
            else r1=mid;
        }
        
        cout<<l<<" "<<l1<<endl;
    }
}

