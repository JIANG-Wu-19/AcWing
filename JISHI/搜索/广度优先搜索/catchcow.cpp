#include<bits/stdc++.h>

using namespace std;

const int N=10005;

struct status
{
    int n,t;
    status(int n,int t): n(n),t(t){}
};

bool visit[N];

int BFS(int n,int k)
{
    queue<status> q;
    q.push(status(n,0));
    visit[n]=true;
    while(!q.empty()){
        status current=q.front();
        q.pop();
        if(current.n==k){
            return current.t;
        }
        for(int i=0;i<3;i++){
            status next(current.n,current.t+1);
            if(i==0){
                next.n++;
            }
            else if(i==1){
                next.n--;
            }
            else{
                next.n*=2;
            }
            if(next.n<0||next.n>N||visit[next.n]){
                continue;
            }
            q.push(next);
            visit[next.n]=true;
        }
    }
}

int main()
{
    int n,k;
    while(cin>>n>>k){
        memset(visit,false,sizeof(visit));
        cout<<BFS(n,k)<<endl;
    }
    return 0;
}
