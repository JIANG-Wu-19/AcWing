#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }

        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            pq.push(x);
        }
        int res=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            pq.push(a+b);
            res+=a+b;
        }
        cout<<res<<endl;

    }
    return 0;
}

