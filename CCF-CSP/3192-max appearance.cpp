#include<iostream>

using namespace std;
const int N=10005;
int a[N],am=0;

int main(){
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=10000;i++){
        if(a[i]>a[am]) am=i;
    }
    cout<<am<<endl;
}
