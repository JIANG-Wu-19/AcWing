#include <iostream>
using namespace std;

int main() {
    int N,X,Y,Z;
    cin>>N;
    cin>>X>>Y>>Z;

    int price;

    for(int price=99999/N;price>=10000/N;price--){
        int total=price*N;

        int b=total%10;
        total/=10;
        int z=total%10;
        total/=10;
        int y=total%10;
        total/=10;
        int x=total%10;
        int a=total/10;

        if(X==x&&Y==y&&Z==z){
            cout<<a<<" "<<b<<" "<<price<<endl;
            return 0;
        }

    }
    cout<<"0"<<endl;

    return 0;
}
