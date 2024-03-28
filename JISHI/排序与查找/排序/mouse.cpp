#include <bits/stdc++.h>
using namespace std;

const int N=105;

struct Mouse{
    string color;
    int weight;
};

Mouse mouse[N];

bool cmp(Mouse a,Mouse b){
    return a.weight>b.weight;
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>mouse[i].weight>>mouse[i].color;
        }

        sort(mouse,mouse+n,cmp);

        for(int i=0;i<n;i++){
            cout<<mouse[i].color<<endl;
        }
    }
}
