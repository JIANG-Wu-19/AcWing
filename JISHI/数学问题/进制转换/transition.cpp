#include <bits/stdc++.h>
#include <string>
using namespace std;

string small(string str){
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]+=32;
        }
    }
    return str;
}

int Char2Int(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }else{
        return c+10-'a';
    }
}

char Int2Char(int x){
    if(x>=0&&x<=9){
        return '0'+x;
    }else{
        return 'A'+x-10;
    }
}

int main() {
    int a,b;
    string n;
    while(cin>>a>>n>>b){
        long long num=0;
        n=small(n);
        int j=1;
        for(int i=n.size()-1;i>=0;i--){
            num+=j*Char2Int(n[i]);
            j*=a;
        }

        if(num==0){
            cout<<"0"<<endl;
            continue;
        }

        vector<char> B;
        while(num){
            B.push_back(Int2Char(num%b));
            num/=b;
        }
        for(int i=B.size()-1;i>=0;i--){
            cout<<B[i];
        }
        cout<<endl;
    }
}
