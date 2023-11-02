#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> div(vector<int> &A,int B,int &r){
    vector<int> C;
    for(int i=0;i<A.size();i++){
        r=r*10+A[i];
        C.push_back(r/B);
        r=r%B;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main(){
    string a;
    int B,r=0;
    cin>>a>>B;
    vector<int> A;
    
    for(int i=0;i<a.size();i++) A.push_back(a[i]-'0');
    
    auto C=div(A,B,r);
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    cout<<endl<<r<<endl;
    
    return 0;
}
