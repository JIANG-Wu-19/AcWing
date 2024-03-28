#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    while(getline(cin,str)){
        unordered_map<char,int> umap;
        for(int i=0;i<str.length();i++){
            umap[str[i]]++;
        }
        for(char i='A';i<='Z';i++){
            cout<<i<<":"<<umap[i]<<endl;
        }
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
