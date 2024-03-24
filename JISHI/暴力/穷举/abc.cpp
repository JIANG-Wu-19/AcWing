#include<iostream>

using namespace std;

int main()
{
    for(int a=0;a<=9;a++){
        for(int b=0;b<=9;b++){
            for(int c=0;c<=9;c++){
                if(100*a+10*b+c+b*100+c*10+c==532){
                    cout<<a<<" "<<b<<" "<<c<<endl;
                }
            }
        }
    }

    return 0;
}
