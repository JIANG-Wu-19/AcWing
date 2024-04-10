#include<bits/stdc++.h>

using namespace std;

//priority<type,vector<type>,greater<type>> 升序队列
//priority<type,vector<type>,less<type>> 降序队列

int main()
{
    int n;
    while(cin>>n){
        priority_queue<int,vector<int>,greater<int>> pq;
        while(n--){
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
