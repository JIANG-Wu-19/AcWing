#include<iostream>

using namespace std;

int main()
{
    int h;

    cin>>h;

    int row=h;
    int col=h+(h-1)*2;

    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(j<=col-(h+2*(i-1))){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }

    return 0;
}
