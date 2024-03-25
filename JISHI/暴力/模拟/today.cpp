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
    int Y,M,D;

    while(cin>>Y>>M>>D){
        int date=0;
        if(isRun(Y)){
            for(int i=1;i<M;i++){
                date+=m2[i];
            }
            date+=D;
        }
        else{
            for(int i=1;i<M;i++){
                date+=m1[i];
            }
            date+=D;
        }
        cout<<date<<endl;
    }

    return 0;
}
