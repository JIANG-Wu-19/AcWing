#include<iostream>
#include<string>
#include<vector>

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

int main()
{
    string num;
    while(cin>>num){
        vector<int> bi;
        while(num.size()){
            int last=num[num.size()-1]-'0';
            bi.push_back(last%2);
            num=divide(num,2);
        }
        for(int i=bi.size()-1;i>=0;i--){
            cout<<bi[i];
        }
        cout<<endl;
    }
    return 0;
}
