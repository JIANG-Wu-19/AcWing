#include<iostream>
#include<algorithm>
#include<cstring>
#define MOD 9901
#define ll long long

using namespace std;

int a,b;

int qPow(int a,int b){
	int ans=1;
	a%=MOD;
	while(b){
		if(b&1){
			ans=ans%MOD*a;
		}
		a=a%MOD*a%MOD;
		b>>=1;
	}
	return ans;
}

ll sum(int p,int c){
	if(!c){
		return 1;
	}
	if(c&1){
		return ((1+qPow(p,(c+1)>>1))*sum(p,(c-1)>>1))%MOD;
	}else{
		return ((1+qPow(p,c>>1))*sum(p,(c>>1)-1)+qPow(p,c))%MOD;
	}
}

int main(){
	cin>>a>>b;
	int ans=1;
	for(int i=2;i<=a;i++){
		int s=0;
		while(a%i==0){
			s++;
			a/=i;
		}#include<iostream>
#include<algorithm>
#include<cstring>
#define MOD 9901
#define ll long long

using namespace std;

int a,b;

int qPow(int a,int b){
	int ans=1;
	a%=MOD;
	while(b){
		if(b&1){
			ans=ans%MOD*a;
		}
		a=a%MOD*a%MOD;
		b>>=1;
	}
	return ans;
}

ll sum(int p,int c){
	if(!c){
		return 1;
	}
	if(c&1){
		return ((1+qPow(p,(c+1)>>1))*sum(p,(c-1)>>1))%MOD;
	}else{
		return ((1+qPow(p,c>>1))*sum(p,(c>>1)-1)+qPow(p,c))%MOD;
	}
}

int main(){
	cin>>a>>b;
	int ans=1;
	for(int i=2;i<=a;i++){
		int s=0;
		while(!(a%i)){
			s++;
			a/=i;
		}
		if(s){
			ans=ans*sum(i,s*b)%MOD;
		}
	}
	if(!a){
		cout<<0<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
		if(s){
			ans=ans*sum(i,s*b)%MOD;
		}
	}
	if(!a){
		cout<<0<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
