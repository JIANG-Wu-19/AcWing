#include<bits/stdc++.h>

using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int a[10];

    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]){
        int i=0,j=9;

        while(i<j){
            if(a[i]%2==0){
                swap(a[i],a[j]);
                --j;
            }
            else{
                ++i;
            }
        }

        for(int i=0;i<10;i++){
            if(a[i]%2==0){
                j=i;
                break;
            }
        }

        sort(a,a+j,cmp);
        sort(a+j,a+10);

        for(int i=0;i<10;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
