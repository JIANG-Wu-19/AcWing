#include<bits/stdc++.h>

using namespace std;

int n;
double r;

int main(){
	cin>>n>>r;
	r+=1.0;
	double res=0;
	for(int i=0;i<=n;i++){
		int value;
		cin>>value;
		res+=value*pow(r,-i);
	}
	
	cout<<fixed<<setprecision(3)<<res<<endl;
	
}
