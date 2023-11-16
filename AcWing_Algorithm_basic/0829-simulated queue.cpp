#include<iostream>

using namespace std;
const int N=1e6+10;
int queue[N];
int head=0,tail=0;

void push(int x){
    queue[++tail]=x;
}

void pop(){
    queue[++head]=0;
}

void isEmpty(){
    if(head==tail) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int query(){
    cout<<queue[head+1]<<endl;
}

int main(){
    int m;
    cin>>m;
    
    while(m--){
        string op;
        cin>>op;
        if(op=="push"){
            int x;
            cin>>x;
            push(x);
        }
        else if(op=="pop"){
            pop();
        }
        else if(op=="empty"){
            isEmpty();
        }
        else if(op=="query"){
            query();
        }
    }
    
    return 0;
}
