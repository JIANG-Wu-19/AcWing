#include<bits/stdc++.h>

using namespace std;

string divide(string num,int x)
{
    int remainder=0;
    for(int i=0;i<num.size();i++){
        int current=remainder*10+num[i]-'0';
        num[i]=current/x+'0';
        remainder=current%x;
    }
    int pos=0;
    while(num[pos]=='0'){
        pos++;
    }

    return num.substr(pos);
}

string multiply(string num,int x)
{
    int carry=0;
    for(int i=num.size()-1;i>=0;i--){
        int current=x*(num[i]-'0')+carry;
        num[i]=current%10+'0';
        carry=current/10;
    }
    if(carry!=0){
        num="1"+num;
    }
    return num;
}

string add(string num,int x)
{
    int carry=x;
    for(int i=num.size()-1;i>=0;i--){
        int current=(num[i]-'0')+carry;
        num[i]=current%10+'0';
        carry=current/10;
    }
    if(carry!=0){
        num="1"+num;
    }
    return num;
}

int main()
{
    string num;
    while(cin>>num){
        vector<int> bi;
        while(num.size()!=0){
            int last=num[num.size()-1]-'0';
            bi.push_back(last%2);
            num=divide(num,2);
        }
        string result="0";
        for(int i=0;i<bi.size();i++){
            result=multiply(result,2);
            result=add(result,bi[i]);
        }
        cout<<result<<endl;
    }
}
