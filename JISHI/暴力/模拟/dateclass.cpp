#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int table[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    while(n>0){
        int y,m,d;
        cin>>y>>m>>d;
        if(d==table[m-1]&&m!=12){
            m=m+1;
            d=1;
        }
        else if(d==table[m-1]&&m==12){
            y=y+1;
            m=1;
            d=1;
        }
        else
            d=d+1;
        if(m<10)
            cout<<y<<"-0"<<m;
        else
            cout<<y<<"-"<<m;
        if(d<10)
            cout<<"-0"<<d<<endl;
        else
            cout<<"-"<<d<<endl;
        n--;
    }
}
