#include<bits/stdc++.h>

using namespace std;

int countNodes(int m,int n)
{
    if(m>n){
        return 0;
    }
    return 1+countNodes(m*2,n)+countNodes(m*2+1,n);
}

int main()
{
    int m,n;
    while(cin>>m>>n){
        cout<<countNodes(m,n)<<endl;
    }
}
