#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin>>n){
        vector<int> bi;
        while(n){
            bi.push_back(n%2);
            n=n>>1;
        }
        for(int i=bi.size()-1;i>=0;i--){
            cout<<bi[i];
        }
        cout<<endl;
    }
}
