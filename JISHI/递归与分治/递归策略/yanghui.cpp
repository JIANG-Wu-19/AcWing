#include<bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int C(int n,int m)
{
    return factorial(n)/(factorial(m)*factorial(n-m));
}

int main()
{
    int n;
    while(cin>>n){
        int i=1;
        while(i*(i+1)/2<n){
            i++;
        }
        int j=n-(i-1)*i/2;

        cout<<C(i-1,j-1)<<endl;
    }
}
