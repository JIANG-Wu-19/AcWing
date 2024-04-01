#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int N = 31623;

bool isPrime[N];
vector<int> prime;

void init() {
    for (int i = 0; i < N; i++) {
        isPrime[i] = true;
    }

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i < N; i++) {
        if (!isPrime[i]) {
            continue;
        } else {
            prime.push_back(i);
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int count(int num){
    int result=1;
    unordered_map<int,int> umap;

    for(int i=0;i<prime.size()&&prime[i]<num;i++){
        while(num%prime[i]==0){
            num/=prime[i];
            umap[prime[i]]++;
        }
    }
    if(num>1){
        umap[num]++;
    }

    for(auto it:umap){
        result*=(it.second+1);
    }

    return result;
}

int main() {
    init();

    int n;
    int num[1005];

    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        for(int i=0;i<n;i++){
            cout<<count(num[i])<<endl;
        }
    }

    return 0;
}
