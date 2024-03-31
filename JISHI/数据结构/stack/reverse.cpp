#include<bits/stdc++.h>

using namespace std;

stack<long long> s;

int main()
{
    int n;
    while(cin>>n){
        while(n--){
            long long num;
            cin>>num;
            s.push(num);
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}
