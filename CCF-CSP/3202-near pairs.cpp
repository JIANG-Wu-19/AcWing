#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;
int num[N];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    
    int cnt=0;
    sort(num,num+n);
    
    for(int i=0;i<n-1;i++){
        if(num[i]+1==num[i+1]) cnt++;
    }
    
    cout<<cnt<<endl;
}
