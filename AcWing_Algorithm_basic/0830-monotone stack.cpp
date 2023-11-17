#include<iostream>

using namespace std;
const int N=1e6+10;
int stack[N],top;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        while(top && stack[top]>=x) top--;
        if(!top) cout<<"-1 ";
        else cout<<stack[top]<<" ";
        stack[++top]=x;
    }
    
    return 0;
}

