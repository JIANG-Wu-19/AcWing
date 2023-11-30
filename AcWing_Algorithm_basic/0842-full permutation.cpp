#include<iostream>

using namespace std;
const int N=10;
int num[N],state[N];
int n;

void dfs(int x){
    
    if(x>n){
        for(int i=1;i<=n;i++){
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=1;i<=n;i++){
        if(!state[i]){
            num[x]=i;
            state[i]=1;
            dfs(x+1);
            state[i]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1);
}
