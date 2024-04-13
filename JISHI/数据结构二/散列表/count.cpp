#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
        map<int,int> score;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            score[num]++;
        }
        int num;
        cin>>num;
        cout<<score[num]<<endl;
    }
}
