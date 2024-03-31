#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool isPrime(int x){
    if(x<=1) return false;
    int bound=sqrt(x);
    for(int i=2;i<=bound;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main() {
    int n;
    while(cin>>n){
        if(isPrime(n)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}
