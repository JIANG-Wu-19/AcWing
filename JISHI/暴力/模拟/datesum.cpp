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

int today(int Y,int M,int D)
{
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
    return date;
}

void back(int y,int date)
{
    int i=0;
    int d=date;
    if(isRun(y)){
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

    cout<<y<<"-";

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

int main()
{
    int m;
    int y,mon,d,n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>y>>mon>>d>>n;
        int date=today(y,mon,d);
        date+=n;

        while(date>0){
            if(isRun(y)){
                date-=366;
            }
            else{
                date-=365;
            }
            y++;
        }

        y--;
        if(isRun(y)){
            date+=366;
        }
        else{
            date+=365;
        }

        back(y,date);
    }

    return 0;
}
