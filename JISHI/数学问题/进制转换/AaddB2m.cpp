#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    while(cin>>m){
        if(m==0){
            break;
        }

        long long A,B;
        cin>>A>>B;

        long long num=A+B;
        vector<int> mNum;

        if(num==0){
            cout<<"0"<<endl;
            continue;
        }

        while(num){
            mNum.push_back(num%m);
            num/=m;
        }

        for(int i=mNum.size()-1;i>=0;i--){
            cout<<mNum[i];
        }
        cout<<endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
