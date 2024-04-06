#include<bits/stdc++.h>

using namespace std;

const int N=25;
int volumn[N],res=0;

void dfs(int cur,int j,int n)
{
    for(int i=j;i<n;i++){
        int now=cur+volumn[i];
        if(now>40){
            dfs(cur,i+1,n);
        }
        else if(now<40){
            dfs(now,i+1,n);
        }
        else{
            res++;
        }
    }
}

int main()
{
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>volumn[i];
        }
        dfs(0,0,n);
        cout<<res<<endl;
    }


}
