#include<iostream>

using namespace std;

const int N=1000009;

int prime[N],num,n;
bool v[N];

void get_prime(int n){
	v[1]=true;
	for(int i=2;i<=n;i++){
		if(!v[i]){
			prime[num++]=i;
		}
		for(int j=0;prime[j]<=n/i;j++){
			v[prime[j]*i]=true;
			if(!(i%prime[j])) break;
		}
	}
}

int main(){
	get_prime(N-5);
	
	while(cin>>n&&n){
		int i=1;
		while(i){
			if(!v[n-prime[i]]){
				cout<<n<<" = "<<prime[i]<<" + "<<n-prime[i]<<endl;
				break;
			}
			i++;
		}
	}
}


