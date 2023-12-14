#include<iostream>

using namespace std;
int n,q;

void divide(int q){
    for(int i=2;i<=q/i;i++){
        if(q%i==0){
            int s=0;
            while(q%i==0){
                q/=i;
                s++;
            }
            cout<<i<<" "<<s<<endl;
        }
    }
    if(q>1) cout<<q<<" 1"<<endl;
    cout<<endl;
}

int main(){
    cin>>n;
    
    while(n--){
        cin>>q;
        divide(q);
    }
    
    return 0;
}
