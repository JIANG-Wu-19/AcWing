#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    vector<string> str;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        str.push_back(s.substr(i,s.size()-i));
    }
    sort(str.begin(),str.end());
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<endl;
    }

}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
