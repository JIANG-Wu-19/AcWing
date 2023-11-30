#include<iostream>

using namespace std;

const int N=1005;
int h[N];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    
    int res=0;
    
    for(int i=1;i<=n;i++){
        int l,r;
        for(int j=i;j>=1;j--){
            if(h[i]>h[j]) break;
            l=j;
        }
        for(int j=i;j<=n;j++){
            if(h[i]>h[j]) break;
            r=j;
        }
        
        res=max(res,(r-l+1)*h[i]);
    }
    
    cout<<res<<endl;
}
