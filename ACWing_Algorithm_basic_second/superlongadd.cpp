#include<iostream>
#include<vector>

using namespace std;

const int N=1e6+10;
vector<int> A,B;

vector<int> add(vector<int> &a,vector<int> &b){
    vector<int> c;
    //t���ڼ�¼��λ
    int t=0;
    for(int i=0;i<a.size()||i<b.size();i++){
        if(i<a.size()) t+=a[i];
        if(i<b.size()) t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t) c.push_back(1);
    return c;
}

int main(){
    string a,b;
    cin>>a>>b;
    
    //�����������洢�������ĵ�λ���������ĵ�λ
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    
    vector<int> c=add(A,B);
    
    //����������������Ǹ�λ��ǰ
    for(int i=c.size()-1;i>=0;i--) cout<<c[i];
    
    cout<<endl;
    
    return 0;
}
