#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int num[N];

bool cmp(int a,int b)
{
    return a<b;
}

int main()
{
    int n,k;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        sort(num,num+n,cmp);
        cin>>k;
        if(k==1){
            cout<<num[0]<<endl;
        }
        int i=0;
        while(k>1){
            int current=num[i];
            while(current==num[i]){
                i++;
            }
            k--;
        }
        cout<<num[i]<<endl;
//        priority_queue<int,vector<int>,greater<int>> pq;
//        while(n--){
//            int x;
//            cin>>x;
//            pq.push(x);
//        }
//
//        cin>>k;
//
//        if(k==1){
//            cout<<pq.top()<<endl;
//            continue;
//        }
//
//        while(k>1){
//            int num=pq.top();
//            while(pq.top()==num){
//                pq.pop();
//            }
//            k--;
//        }
//
//        cout<<pq.top()<<endl;
    }
    return 0;
}
