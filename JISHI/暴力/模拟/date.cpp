#include<iostream>

using namespace std;

int m1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int m2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

bool isRun(int Y)
{
    if(Y%100==0){
        if(Y%400==0) return true;
        else return false;
    }
    else{
        if(Y%4==0) return true;
        else return false;
    }
}

int main()
{
    int m,n;

    while(cin>>m>>n){
        int i=0;
        int d=n;
        if(isRun(m)){
            while(d>0){
                i++;
                d-=m2[i];
            }
            d+=m2[i];
        }
        else{
            while(d>0){
                i++;
                d-=m1[i];
            }
            d+=m1[i];
        }

        cout<<m<<"-";

        if(i<10){
            cout<<"0"<<i<<"-";
        }
        else{
            cout<<i<<"-";
        }

        if(d<10){
            cout<<"0"<<d<<endl;
        }
        else{
            cout<<d<<endl;
        }
    }

    return 0;
}
