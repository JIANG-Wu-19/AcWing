#include<iostream>

using namespace std;

const int N=10000;
const int M=1000;

void getNext(int next[],int pattern[],int m)
{
    int j=0;
    next[j]=-1;

    int i=next[j];

    while(j<m){
        if(i==-1||pattern[j]==pattern[i]){
            i++;
            j++;
            next[j]=i;
        }
        else{
            i=next[i];
        }
    }
}

int KMP(int next[],int pattern[],int text[],int n,int m)
{
    getNext(next,pattern,m);
    int i=0;
    int j=0;
    while(i<n&&j<m){
        if(j==-1||text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
        if(j==m){
            return i-j+1;
        }
        else{
            return -1;
        }
    }
}

int main()
{
    int next[M];
    int pattern[M];
    int text[N];
    int num;
    cin>>num;
    while(num--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>text[i];
        }
        for(int i=0;i<n;i++){
            cin>>pattern[i];
        }
        cout<<KMP(next,pattern,text,n,m)<<endl;
    }
}
