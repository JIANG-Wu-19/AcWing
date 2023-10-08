#include<iostream>
#include<algorithm>

using namespace std;

const int N=100010;
int a[N],b[N];
int n;
long long pos,neg;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	
	for(int i=2;i<=n;i++){
		if(b[i]>0){
			pos+=b[i];
		}else{
			neg-=b[i];
		}
	}
	
	cout<<min(pos,neg)+abs(pos-neg)<<endl;
	cout<<abs(pos-neg)+1<<endl;
	
	return 0;
}
