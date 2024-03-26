#include<bits/stdc++.h>

using namespace std;
const int N=121;

struct Student
{
    int no;
    int score;
    string name;
};

Student student[N];

bool ASC(Student a,Student b)
{
    if(a.score==b.score){
        return a.no<b.no;
    }
    else{
        return a.score<b.score;
    }
}

bool DESC(Student a,Student b)
{
    if(a.score==b.score){
        return a.no<b.no;
    }
    else{
        return a.score>b.score;
    }
}

int main()
{
    int n,order;
    while(cin>>n>>order){
        for(int i=1;i<=n;i++){
            student[i].no=i;
            cin>>student[i].name>>student[i].score;
        }

        if(order){
            sort(student+1,student+n+1,ASC);
        }
        else{
            sort(student+1,student+n+1,DESC);
        }

        for(int i=1;i<=n;i++){
            cout<<student[i].name<<" "<<student[i].score<<endl;
        }
    }

    return 0;
}
