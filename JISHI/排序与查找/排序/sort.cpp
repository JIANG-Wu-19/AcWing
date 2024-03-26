#include<bits/stdc++.h>

using namespace std;

const int N=105;

int num[N];

int main()
{
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }

//        sort(first,last,comp);
        sort(num+1,num+n+1);

        for(int i=1;i<=n;i++){
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
