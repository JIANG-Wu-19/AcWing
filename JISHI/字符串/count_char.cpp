#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string find;
    while(getline(cin,find)){
        if(find=="#") break;
        string str;
        getline(cin,str);
        unordered_map<char,int> umap;
        for(int i=0;i<str.length();i++){
            umap[str[i]]++;
        }
        for(int i=0;i<find.length();i++){
            cout<<find[i]<<" "<<umap[find[i]]<<endl;
        }
        find.clear();
    }
}
