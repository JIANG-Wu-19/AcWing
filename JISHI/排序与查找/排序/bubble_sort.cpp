#include<iostream>

using namespace std;

const int N=105;
int num[N];

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void bubble_sort(int num[],int n)
{
    for(int i=1;i<n;i++){
        for(int j=1;j<n-i+1;j++){
            if(num[j]>num[j+1])
                swap(num[j],num[j+1]);
        }
    }
}

int main()
{
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }

        bubble_sort(num,n);

        for(int i=1;i<=n;i++)
            cout<<num[i]<<" ";
        cout<<endl;
    }
    return 0;
}
