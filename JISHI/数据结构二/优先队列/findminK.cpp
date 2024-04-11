#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    while(cin>>n){
        priority_queue<int,vector<int>,greater<int>> pq;
        while(n--){
            int x;
            cin>>x;
            pq.push(x);
        }

        cin>>k;

        if(k==1){
            cout<<pq.top()<<endl;
            continue;
        }

        while(k>1){
            int num=pq.top();
            while(pq.top()==num){
                pq.pop();
            }
            k--;
        }

        cout<<pq.top()<<endl;
    }
    return 0;
}
