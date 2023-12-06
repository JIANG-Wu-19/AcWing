#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

const int N=100010;

double s1[N],s2[N];	

int main(){
	int n,m;
	cin>>n>>m;
	s1[0]=1.0;
	s2[0]=0.0;
	for(int i=1;i<=n;i++){
		int kind;
		double para;
		
		cin>>kind>>para;
		
		if(kind==1){
			s1[i]=s1[i-1]*para;
			s2[i]=s2[i-1];
		}else{
			s1[i]=s1[i-1];
			s2[i]=s2[i-1]+para;
		}
		
	}
	
	while(m--){
		int i,j;
		double x,y;
		cin>>i>>j>>x>>y;
		
		x=s1[j]/s1[i-1]*x;
		y=s1[j]/s1[i-1]*y;
			
		auto a=x;
		auto b=y;
			
		x=a*cos(s2[j]-s2[i-1])-b*sin(s2[j]-s2[i-1]);
		y=a*sin(s2[j]-s2[i-1])+b*cos(s2[j]-s2[i-1]);
			
		cout<<fixed<<setprecision(3)<<x<<" "<<y<<endl;
		
	}
	return 0;			
}
