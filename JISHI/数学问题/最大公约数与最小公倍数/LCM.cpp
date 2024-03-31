#include<bits/stdc++.h>

using namespace std;

int GCD(int m,int n)
{
    return n==0? m:GCD(n,m%n);
}

//LCM=m*n/GCD(m,n)

int main()
{
    int m,n;
    while(cin>>m>>n){
        cout<<m*n/GCD(m,n)<<endl;
    }
    return 0;
}
