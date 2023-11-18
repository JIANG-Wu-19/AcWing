#include<iostream>

using namespace std;
const int N=1e7+10;
int num[N],queue[N],head,tail=-1;

int main(){
    int n,k;
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(i-k+1>queue[head]) ++head;
        while(head<=tail && num[i]<=num[queue[tail]]) --tail;
        queue[++tail]=i;
        if(i+1>=k) cout<<num[queue[head]]<<" ";
    }
    
    cout<<endl;
    head=0;
    tail=-1;
    
    for(int i=0;i<n;i++){
        if(i-k+1>queue[head]) ++head;
        while(head<=tail && num[i]>=num[queue[tail]]) --tail;
        queue[++tail]=i;
        if(i+1>=k) cout<<num[queue[head]]<<" ";
    }
    cout<<endl;
    return 0;
}
