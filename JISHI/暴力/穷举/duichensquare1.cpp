#include<iostream>

using namespace std;

int reverse(int n)
{
    int rev=0;
    while(n){
        rev*=10;
        rev+=n%10;
        n/=10;
    }
    return rev;
}

int main()
{
    for(int i=0;i<=256;i++){
        if(reverse(i*i)==(i*i)){
            cout<<i<<endl;
        }
    }

    return 0;
}
