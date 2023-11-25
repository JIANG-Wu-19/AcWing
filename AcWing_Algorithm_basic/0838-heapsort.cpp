#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;
int heap[N],hsize;
int n,m;

void down(int x){
    int t=x;
    if(x*2<=hsize&&heap[x*2]<heap[t]) t=x*2;
    if(x*2+1<=hsize&&heap[x*2+1]<heap[t]) t=x*2+1;
    if(t!=x){
        swap(heap[t],heap[x]);
        down(t);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>heap[i];
    
    hsize=n;
    for(int i=n/2;i;i--) down(i);
    
    while(m--){
        cout<<heap[1]<<" ";
        heap[1]=heap[hsize];
        hsize--;
        down(1);
    }
    
    return 0;
}
