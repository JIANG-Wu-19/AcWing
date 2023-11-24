#include<iostream>
using namespace std;

const int N=1e5+10;
int fa[N],d[N];

int find(int x){
    if(fa[x]==x) return x;
    int r=find(fa[x]);
    d[x]+=d[fa[x]];
    return fa[x]=r;
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans=0;
    
    while(k--){
        int t,a,b;
        cin>>t>>a>>b;
        if(a>n||b>n){
            ans++;
            continue;
        }else if(t==2&&a==b){
            ans++;
            continue;
        }else{
            int rel;
            if(t==2) rel=1;
            else rel=0;
            int x=find(a),y=find(b);
            if(x==y){
                if((((d[a] - d[b]) % 3) + 3) % 3 != rel) ans++;
            }
            else{
                fa[x]=y;
                d[x]=d[b]-(d[a]-rel);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
