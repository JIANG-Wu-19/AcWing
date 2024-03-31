#include <bits/stdc++.h>
using namespace std;

char Int2Char(int x){
    if(x<=9){
        return '0'+x;
    }
    else{
        return 'a'+x-10;
    }
}

int Char2Int(char x){
    if(x>='0'&&x<='9'){
        return x-'0';
    }else{
        return x+10-'A';
    }
}

int main() {
    int M,N;

    while(cin>>M>>N){
        long long number=0;
        string num;
        cin>>num;
        for(int i=0;i<num.size();i++){
            number*=M;
            number+=Char2Int(num[i]);
        }
        vector<char> n;
        while(number){
            n.push_back(Int2Char(number%N));
            number/=N;
        }
        for(int i=n.size()-1;i>=0;i--){
            cout<<n[i];
        }
        cout<<endl;
    }
}

