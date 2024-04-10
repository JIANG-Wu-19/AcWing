#include<bits/stdc++.h>

using namespace std;

struct Complex
{
    int real;
    int imag;

    Complex(int x,int y):real(x),imag(y){}

    bool operator< (Complex c) const
    {
        return real*real+imag*imag<c.real*c.real+c.imag*c.imag;
    }
};

int main()
{
    int n;
    while(cin>>n){
            priority_queue<Complex> pq;
            while(n--){
                string str;
                cin>>str;
                if(str=="Pop"){
                    if(pq.empty()){
                        cout<<"empty"<<endl;
                    }
                    else{
                        Complex current=pq.top();
                        pq.pop();
                        cout<<current.real<<"+i"<<current.imag<<endl;
                        cout<<"SIZE = "<<pq.size()<<endl;
                    }
                }
                else{
                    int a,b;
                    scanf("%d+i%d",&a,&b);
                    pq.push(Complex(a,b));
                    cout<<"SIZE = "<<pq.size()<<endl;
                }
            }
    }

    return 0;
}
