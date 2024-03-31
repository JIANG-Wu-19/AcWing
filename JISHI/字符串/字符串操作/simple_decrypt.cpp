#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    string str;
    while(getline(cin,str)){
        if(str=="ENDOFINPUT"){
            break;
        }
        getline(cin,str);
        for(int i=0;i<str.length();i++){
            if(str[i]>='A'&&str[i]<='Z'){
                str[i]='A'+(str[i]-'A'-5+26)%26;
            }
        }

        cout<<str<<endl;
        getline(cin,str);
        return 0;
    }
}
