#include<iostream>
#include<algorithm>

using namespace std;

const int N=100005;
int cows[N];
double sum[N];

int n,m;

double check(double avg){
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+cows[i]-avg;
	}
	
	double minv=0;
	
	for(int i=0,j=m;j<=n;i++,j++){
		minv=min(minv,sum[i]);
		if(sum[j]-minv>=0) return true;
	}
	return false;
}

int main(){
	cin>>n>>m;
	double l=0,r=0;
	for(int i=1;i<=n;i++){
		cin>>cows[i];
		r=max(r,double(cows[i]));
	}
	
	while(r-l>1e-5){
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<int(r*1000)<<endl;
	return 0;
	
}
