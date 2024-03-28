#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int,int> umap;

int main() {
    int n,m;
    while(cin>>n){
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            umap[num]=i;
        }

        cin>>m;

        for(int i=0;i<m;i++){
            int num;
            cin>>num;
            if(umap.find(num)!=umap.end()){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
