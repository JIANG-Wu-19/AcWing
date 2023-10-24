#include<iostream>

using namespace std;
typedef long long ll;

const int N=501000;
ll n,m,i,j,k,a[N],b[N],num;

void merge(ll a[],ll l,ll r){
	if(r-l<1){
		return;
	}
	ll mid=(l+r)>>1;
	merge(a,l,mid);
	merge(a,mid+1,r);
	ll i=l,j=mid+1;
	for(ll k=l;k<=r;k++){
		if(j>r||i<=mid&&a[i]<=a[j]) b[k]=a[i++];
		else{
			num+=mid-i+1;
			b[k]=a[j++];
		}
	}
	for(ll k=l;k<=r;k++){
		a[k]=b[k];
	}
}


int main(){
	cin.tie(0);
	cout.tie(0);
	while(cin>>n&&n){
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		num=0;
		merge(a,1,n);
		cout<<num<<endl;
	}
	return 0;
}
