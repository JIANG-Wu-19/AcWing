#include<iostream>

using namespace std;

const int N=110;

int g[N][N];
int n;

int main(){
    cin>>n;
    while(n--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<x2;i++){
            for(int j=y1;j<y2;j++){
                    g[i][j]=1;
            }
        }
    }
    
    int res=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            res+=g[i][j];
        }
    }
    
    cout<<res<<endl;
    
    return 0;
}

