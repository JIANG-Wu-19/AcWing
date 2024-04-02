#include<iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n){
        if(n%2==1){
            cout<<"0 0"<<endl;
        }
        int maxmum,minimum;

        maxmum=n/2;
        minimum=n/4+(n%4)/2;

        cout<<minimum<<" "<<minimum<<endl;
    }
}
