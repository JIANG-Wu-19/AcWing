#include<iostream>

using namespace std;

//int reverse(int n)
//{
//    int rev=0,k=1000;
//    while(n){
//        rev+=k*(n%10);
//        n/=10;
//        k/=10;
//    }
//    return rev;
//}

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
    for(int n=1000;n<=1111;n++){
        int rev=reverse(n);
        if(n*9==rev)
            cout<<n<<endl;
    }

    return 0;
}
