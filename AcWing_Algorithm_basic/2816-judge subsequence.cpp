#include<iostream>

using namespace std;

const int N=100010;
int a[N],b[N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    int k=1;
    // for(int i=1;i<=n;i++){
    //     int j=k;
    //     while(a[i]!=b[j]){
    //         j++;
    //         if(j==m+1){
    //             cout<<"No"<<endl;
    //             return 0;
    //         }
    //     }
    //     k=j;
    // }
    
    int i=1;
    for(int j=1;j<=m;j++){
        if(i<=n&&a[i]==b[j]) i++;
    }
    
    if(i==n+1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
