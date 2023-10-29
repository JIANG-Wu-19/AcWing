#include<iostream>
#include<iomanip>

using namespace std;


int main(){
	double n;
	cin>>n;
	double l=-10005.0,r=10005.0;
	while(r-l>1e-8){
		double mid=(l+r)/2;
		if(mid*mid*mid>=n) r=mid;
		else l=mid;
	}
	cout<<fixed<<setprecision(6)<<l<<endl;
}
