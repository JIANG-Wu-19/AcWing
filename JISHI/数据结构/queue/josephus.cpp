#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n,p,m;

    while(cin>>n>>p>>m){
        queue<int> q;
        if(n==0&&p==0&&m==0){
            break;
        }
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        for(int i=1;i<p;i++){
            q.push(q.front());
            q.pop();
        }

        while(!q.empty()){
            for(int i=1;i<m;i++){
                q.push(q.front());
                q.pop();
            }
            if(q.size()==1){
                cout<<q.front()<<endl;
            }
            else{
                cout<<q.front()<<",";
            }
            q.pop();
        }
    }

    return 0;
}
