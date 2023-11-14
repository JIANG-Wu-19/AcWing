#include<iostream>
#include<string>

using namespace std;

const int N=1e6+10;
int stack[N];
int s_pointer=0;

void push(int x){
    stack[++s_pointer]=x;
}

void pop(){
    stack[s_pointer--]=0;
}

void query(){
    cout<<stack[s_pointer]<<endl;
}

void isEmpty(){
    if(s_pointer){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}

int main(){
    int m;
    cin>>m;
    
    while(m--){
        string s;
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            push(x);
        }
        else if(s=="pop"){
            pop();
        }
        else if(s=="query"){
            query();
        }
        else if(s=="empty"){
            isEmpty();
        }
    }
    
    return 0;
}
