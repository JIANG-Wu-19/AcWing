#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1,str2;
    int result=0;
    while(cin>>str1>>str2){
        for(int i=0;i<str1.length();i++){
            for(int j=0;j<str2.length();j++){
                result+=(str1[i]-'0')*(str2[j]-'0');
            }
        }

        cout<<result<<endl;
    }
    return 0;
}
