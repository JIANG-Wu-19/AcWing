#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;


int main(){
    string str;
    while(cin>>str){
        vector<int> num[128];

        for(int i=0;i<str.length();i++){
            num[str[i]].push_back(i);
        }

        unordered_map<char,int> umap;

        for(int i=0;i<str.length();i++){
            if(num[str[i]].size()>1&&umap.find(str[i])==umap.end()){
                umap[str[i]]=1;
                for(int j=0;j<num[str[i]].size();j++){
                    if(j!=num[str[i]].size()-1){
                        cout<<str[i]<<":"<<num[str[i]][j]<<",";
                    }
                    else{
                        cout<<str[i]<<":"<<num[str[i]][j]<<endl;
                    }
                }
            }
        }
    }

    return 0;
}
