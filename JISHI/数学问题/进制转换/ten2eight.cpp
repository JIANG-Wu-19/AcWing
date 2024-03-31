#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while(cin>>N){
        vector<int> Oct;
        while(N){
            Oct.push_back(N%8);
            N/=8;
        }
        for(int i=Oct.size()-1;i>=0;i--){
            cout<<Oct[i];
        }
        cout<<endl;
    }
}
