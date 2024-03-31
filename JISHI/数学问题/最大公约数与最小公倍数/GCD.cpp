#include<bits/stdc++.h>

using namespace std;

//int main()
//{
//    int m,n;
//    while(cin>>m>>n){
//        int gcd=1;
//        for(int i=2;i<=min(m,n);i++){
//            if(m%i==0&&n%i==0&&i>gcd){
//                gcd=i;
//            }
//        }
//        cout<<gcd<<e
//    }
//}
int GCD(int m,int n)
{
    return n==0? m:GCD(n,m%n);
}

int main()
{
    int m,n;
    while(cin>>m>>n){
        cout<<GCD(m,n)<<endl;
    }
    return 0;
}
