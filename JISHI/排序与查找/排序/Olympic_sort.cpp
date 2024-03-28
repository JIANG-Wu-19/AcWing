#include <iostream>
#include<cstdio>
using namespace std;

const int N=10;

int main(){
    int n,m;
    while(cin>>n>>m){
        int country[N][3];

        for(int i=0;i<n;i++){
            cin>>country[i][0]>>country[i][1]>>country[i][2];
        }

        double method[N][4];
        int rank[N][4]={0};

        for(int i=0;i<m;i++){
            int country_id;
            cin>>country_id;
            method[i][0]=country[country_id][0];
            method[i][1]=country[country_id][1];
            method[i][2]=country[country_id][0]?1.0*country[country_id][0]/country[country_id][2]:0;
            method[i][3]=country[country_id][1]?1.0*country[country_id][1]/country[country_id][2]:0;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    if(method[j][k]>method[i][k]){
                        rank[i][k]++;
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            int min=0;
            for(int j=1;j<4;j++){
                if(rank[i][j]<rank[i][min]){
                    min=j;
                }
            }
            cout<<rank[i][min]+1<<":"<<min+1<<endl;
        }
        cout<<endl;
    }
}
