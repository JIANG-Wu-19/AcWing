#include<bits/stdc++.h>

using namespace std;

const int N=100;
int res[100];

void init()
{
    for(int i=1;i<=N;i++){
        if(i==1){
            res[i]=1;
        }
        else if(i==2){
            res[i]=2;
        }
        else{
            res[i]=res[i-1]+res[i-2];
        }
    }
}

int main()
{
    init();
    int n;
    while(cin>>n){
        cout<<res[n]<<endl;
    }
    return 0;
}
