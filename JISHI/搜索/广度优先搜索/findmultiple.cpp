#include<bits/stdc++.h>

using namespace std;

void BFS(int n)
{
    queue<long long> q;
    q.push(1);
    while(!q.empty()){
        long long current=q.front();
        q.pop();
        if(current%n==0){
            cout<<current<<endl;
            return;
        }
        q.push(current*10);
        q.push(current*10+1);
    }
}

int main()
{
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
        BFS(n);
    }
    return 0;
}
