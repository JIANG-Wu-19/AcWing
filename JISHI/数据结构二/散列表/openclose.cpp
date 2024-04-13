#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n){
        string open,close,earliest="23:59:59",latest="00:00:00";
        string no,arrive,leave;
        for(int i=0;i<n;i++){
            cin>>no>>arrive>>leave;
            if(arrive<earliest){
                open=no;
                earliest=arrive;
            }
            if(leave>latest){
                close=no;
                latest=leave;
            }
        }
        cout<<open<<" "<<close<<endl;
    }

    return 0;
}
