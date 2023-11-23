#include<iostream>

using namespace std;
const int N=1e5+10;
int n,m,a,b,fa[N],cnt[N];
char op[2];

void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        cnt[i]=1;
    }
}

int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

void merge(int a,int b){
    int x=find(a);
    int y=find(b);
    fa[x]=y;
    cnt[y]+=cnt[x];
}

bool query(int a,int b){
    return find(a)==find(b);
}

int main(){
    cin>>n>>m;
    
    init();
    
    while(m--){
        cin>>op;
        if(*op=='C'){
            cin>>a>>b;
            if(!query(a,b)) merge(a,b);
        }else{
            if(op[1]=='1'){
                cin>>a>>b;
                if(query(a,b)){
                    cout<<"Yes"<<endl;
                }else{
                    cout<<"No"<<endl;
                }
            }else{
                cin>>a;
                cout<<cnt[find(a)]<<endl;
            }
        }
    }
    return 0;
}
