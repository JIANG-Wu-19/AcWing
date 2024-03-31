#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main() {
    vector<int> E;
    vector<int> G;

    for(int i=2;i<=60;i++){
        int num=i;
        vector<int> factor;
        for(int j=1;j<num;j++){
            if(num%j==0){
                factor.push_back(j);
            }
        }
        int sum=0;
        for(int j=0;j<factor.size();j++){
            sum+=factor[j];
        }
        if(sum>num){
            G.push_back(num);
        }
        else if(sum==num){
            E.push_back(num);
        }
    }

    cout<<"E: ";
    for(int i=0;i<E.size();i++){
        cout<<E[i]<<" ";
    }

    cout<<"G: 2 ";
    //2ÊÇ´íµÄ
    for(int i=0;i<G.size();i++){
        cout<<G[i]<<" ";
    }
    cout<<endl;

    return 0;
}
