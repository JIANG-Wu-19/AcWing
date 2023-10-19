#include<iostream>

using namespace std;

const int N=1000010;
int prime[N],primeNum=0;
bool notPrime[2*N];

void initPrime(int x){
	for(int i=2;i<=x;i++){
		if(notPrime[i]) continue;
		for(int j=2;j<=x/i;j++){
			notPrime[i*j]=1;
		}
	}
	for(int i=2;i<=x;i++){
		if(!notPrime[i]) prime[++primeNum]=i;
	}
}

int main(){
	int n;
	cin>>n;
	initPrime(n);
	for(int i=1;i<=primeNum;i++){
		int tmpN=n,nowprime=prime[i],nowres=0;
		while(tmpN){
			nowres+=(tmpN/nowprime);
			tmpN/=nowprime;
		}
		cout<<nowprime<<" "<<nowres<<endl;
	}
	return 0;
}
			


