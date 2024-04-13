#include<bits/stdc++.h>

using namespace std;

const int N=205;
int book[N];

int main()
{
    int n,m;
    while(cin>>n>>m){
        map<int,int> num;
        for(int i=1;i<=n;i++){
            cin>>book[i];
            num[book[i]]++;
        }
        for(int i=1;i<=n;i++){
            int n=num[book[i]];
            if(n==1){
                cout<<"BeiJu"<<endl;
            }
            else{
                cout<<n-1<<endl;
            }
        }
    }
}
