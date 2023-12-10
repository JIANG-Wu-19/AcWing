#include<bits/stdc++.h>

using namespace std;
int a[1005];
int n;
double avg=0.0,d=0,s=0;

int main(){
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		avg+=a[i];
	}
	avg/=(double)n;
	
	for(int i=1;i<=n;i++){
		d+=(a[i]-avg)*(a[i]-avg);
	}
	
	d/=(double)n;
	d=sqrt(d);
	
	for(int i=1;i<=n;i++){
		cout<<fixed<<setprecision(16)<<(a[i]-avg)/d<<" ";
	}
	cout<<endl;
	return 0;
}
	
