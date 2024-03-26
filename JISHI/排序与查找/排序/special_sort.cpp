#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int num[N];

int main(){
    int n;
    while(cin>>n){
        if(n==1){
            cin>>num[1];
            cout<<num[1]<<endl;
            cout<<"-1"<<endl;
            continue;
        }

        for(int i=1;i<=n;i++){
            cin>>num[i];
        }

        sort(num+1,num+n+1);

        cout<<num[n]<<endl;
        for(int i=1;i<n;i++){
            cout<<num[i]<<" ";
        }

        cout<<endl;
    }
}
