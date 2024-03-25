#include <iostream>
#include<string>
using namespace std;

int main() {
    string str;
    while(cin>>str){
        int N=str.length();
        int n1=(N+2)/3;
        int n2=N+2-n1*2;

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(i!=n1-1){
                    if(j==0){
                        cout<<str[i];
                    }
                    else if(j==n2-1){
                        cout<<str[N-1-i]<<endl;
                    }
                    else{
                        cout<<" ";
                    }
                }
                else{
                    cout<<str[n1-1+j];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
