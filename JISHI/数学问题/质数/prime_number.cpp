#include <bits/stdc++.h>
using namespace std;

const int N=110000;
bool isPrime[N];
vector<int> prime;

void init(){
    for(int i=0;i<N;i++){
        isPrime[i]=true;
    }

    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2;i<N;i++){
        if(!isPrime[i]) continue;
        else{
            prime.push_back(i);
            for(int j=i*i;j<N;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

int main() {
    init();
    int n;
    while(cin>>n){
        cout<<prime[n-1]<<endl;
    }
    return 0;
}

