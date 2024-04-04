#include<bits/stdc++.h>

using namespace std;

void fullPermutation(string pre,string str)
{
    if(str.size()==1){
        cout<<pre+str<<endl;
    }
    string nextpre;
    string nextstr;

    for(int i=0;i<str.size();i++){
        nextpre=pre+str[i];
        nextstr=str;
        nextstr.erase(i,1);
        fullPermutation(nextpre,nextstr);
    }
}

int main()
{
    string str;
    while(cin>>str){
        fullPermutation("",str);
    }
}
