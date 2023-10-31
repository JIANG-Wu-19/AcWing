#include<iostream>
#include<vector>

using namespace std;
vector<int> A,B;

bool cmp(vector<int> &A,vector<int> &B){
	if(A.size()!=B.size()) return A.size()>B.size();
	
	for(int i=A.size();i>=0;i--)
		if(A[i]!=B[i]) return A[i]>B[i];
		
	return true;
}

vector<int> sub(vector<int> &A,vector<int> &B){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++){
        t+=A[i];
        if(i<B.size()) t-=B[i];
        if(t>=0){
            C.push_back(t);
            t=0;
        }else{
            C.push_back(t+10);
            t=-1;
        }
    }
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main(){
    string a,b;
    cin>>a>>b;
    
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    
    if(cmp(A,B)){
        vector<int> C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    }else{
        vector<int> C=sub(B,A);
        cout<<'-';
        for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    }
    
    cout<<endl;
    
    return 0;
}
