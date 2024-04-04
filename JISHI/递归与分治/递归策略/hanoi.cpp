#include<bits/stdc++.h>

using namespace std;

long long hanoi(long long n)
{
    if(n==1) return 2;
    return 3*F[n-1]+2;
}

int main()
{
    long long n;
    while(cin>>n){
        cout<<hanoi(n)<<endl;
    }
}
