#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while(getline(cin,str)){
        for(int i=0;i<str.length();i++){
            if(i==0&&str[i]>='a'&&str[i]<='z'){
                str[i]-=32;
            }

            if(str[i-1]==' '||str[i-1]=='\t'||str[i-1]=='\r'||str[i-1]=='\n'){
                if(str[i]>='a'&&str[i]<='z'){
                    str[i]-=32;
                }
            }
        }

        cout<<str<<endl;
    }
}
