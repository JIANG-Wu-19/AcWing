#include <iostream>
#include <algorithm>
using namespace std;
const int N = 40,M = 10010;
int n,m;
int f[N][M * N];
int v[N];
int main(){
    cin>>m>>n;
    for(int i = 1;i <= n;i ++) cin>>v[i];
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            f[i][j] = f[i - 1][j]; 
            if(j >= v[i]) f[i][j] = max(f[i][j],f[i - 1][j - v[i]] + v[i]);
        }
    }
    cout<<m - f[n][m]<<endl;
}
