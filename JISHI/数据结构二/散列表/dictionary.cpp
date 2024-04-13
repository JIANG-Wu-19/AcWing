#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    unordered_map<string,string> umap;
    while(getline(cin,str)){
        if(str=="@END@"){
            break;
        }

        int pos=str.find(']');
        string key=str.substr(0,pos+1);
        string value=str.substr(pos+2);

        umap[key]=value;
        umap[value]=key;
    }

    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        string key;
        getline(cin,key);
        string ans=umap[key];
        if(ans==""){
            cout<<"what?"<<endl;
        }
        else if(ans[0]=='['){
            cout<<ans.substr(1,ans.size()-2)<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }

    return 0;
}
