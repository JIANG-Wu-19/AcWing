#include <bits/stdc++.h>
using namespace std;

const int N=605;
int num[N];

int GCD(int m,int n){
    return n==0? m:GCD(n,m%n);
}

int main() {
    int n;
    while(cin>>n){
        if(n==0) break;

        for(int i=0;i<n;i++){
            cin>>num[i];
        }

        int result=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(GCD(num[i],num[j])==1) result++;
            }
        }
        cout<<result<<endl;
    }
}
