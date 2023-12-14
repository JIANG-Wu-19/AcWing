#include<iostream>
#include<cmath>

using namespace std;

void isPrime(int x){
    if(x==1){
        cout<<"No"<<endl;
        return;
    }
    if(x==2){
        cout<<"Yes"<<endl;
        return;
    }
    for(int i=2;i<=(int)sqrt(x);i++){
        if(!(x%i)){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int n;

int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        isPrime(x);
    }
    return 0;
}
