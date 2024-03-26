#include<bits/stdc++.h>

using namespace std;

const int N=105;

struct Student
{
    int score;
    int no;
};

Student student[N];

bool cmp(Student a,Student b)
{
    if(a.score==b.score){
        return a.no<b.no;
    }
    else{
        return a.score<b.score;
    }
}

int main()
{
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>student[i].no>>student[i].score;
        }

        sort(student+1,student+n+1,cmp);

        for(int i=1;i<=n;i++){
            cout<<student[i].no<<" "<<student[i].score<<endl;
        }
    }
    return 0;
}
