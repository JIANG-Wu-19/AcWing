#include<iostream>
#include<string>

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

int main()
{
    string n1,n2;
    int y1=0,m1=0,d1=0;
    int y2=0,m2=0,d2=0;

    while(cin>>n1>>n2){
        for(int i=0;i<=3;i++){
            y1*=10;
            y2*=10;
            y1+=n1[i]-'0';
            y2+=n2[i]-'0';
        }
        for(int i=4;i<=5;i++){
            m1*=10;
            m2*=10;
            m1+=n1[i]-'0';
            m2+=n2[i]-'0';
        }
        for(int i=6;i<=7;i++){
            d1*=10;
            d2*=10;
            d1+=n1[i]-'0';
            d2+=n2[i]-'0';
        }

        int date1=today(y1,m1,d1);
        int date2=today(y2,m2,d2);

        // cout<<y1<<m1<<d1<<endl;
        // cout<<y2<<m2<<d2<<endl;
        // cout<<date1<<endl;
        // cout<<date2<<endl;

        for(int i=y1;i<y2;i++){
            if(isRun(i)){
                date2+=366;
            }
            else{
                date2+=365;
            }
        }
        cout<<date2-date1+1<<endl;
    }

    return 0;
}
