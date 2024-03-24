#include<iostream>

using namespace std;

bool irrelevant_to_7(int x){
    if(x%7==0) return false;
    while(x){
        int i=x%10;
        if(i==7) return false;
        x/=10;
    }

    return true;
}

int main(){
    int n;
    cin>>n;
    int result=0;

    for(int i=1;i<=n;i++){
        if(irrelevant_to_7(i)){
            result+=i*i;
        }
    }

    cout<<result<<endl;

    return 0;
}
