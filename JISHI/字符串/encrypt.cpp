#include <iostream>
#include <string>
using namespace std;

int main() {
    string secret;
    while(cin>>secret){
        for(int i=0;i<secret.length();i++){
            if(secret[i]=='z'||secret[i]=='Z'){
                secret[i]-=25;
            }
            else if((secret[i]>='a'&&secret[i]<'z')||secret[i]>='A'&&secret[i]<'Z'){
                secret[i]++;
            }
        }
        cout<<secret<<" ";
    }
}
