#include <bits/stdc++.h>
using namespace std;

const int N=1005;

struct Pair{
    int x;
    int y;
};

Pair p[N];

bool cmp(Pair a,Pair b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    else{
        return a.x<b.x;
    }
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
        }

        sort(p,p+n,cmp);

        cout<<p[0].x<<" "<<p[0].y<<endl;
    }
}
