#include<iostream>
#include<unordered_map>

using namespace std;

const int N=510;

int num[N],n,cnt=0;
unordered_map <int,int> umap;

int main(){
    
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    
    for(int i=1;i<=n;i++){
        if(num[i]>0){
            umap.emplace(num[i],i);
        }
    }
    
    for(int i=1;i<=n;i++){
        if(num[i]<0 && umap.find(-num[i])!=umap.end()) cnt++;
    }
    
    cout<<cnt<<endl;
}
