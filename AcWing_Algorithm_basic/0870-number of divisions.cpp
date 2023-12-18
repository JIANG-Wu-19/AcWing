#include<bits/stdc++.h>
#define ll long long


using namespace std;
const int N=1e9+7;

int main(){
    int n;
    unordered_map<int,int> umap;
    ll ans=1;
    cin>>n;
    
    while(n--){
        int x;
        cin>>x;
        
        for(int i=2;i<=x/i;i++){
            while(x%i==0){
                x/=i;
                umap[i]++;
            }
        }
        if(x>1) umap[x]++;
    }
    
    for(auto item:umap){
        ans=ans*(item.second+1)%N;
    }
    cout<<ans<<endl;
    return 0;
}
