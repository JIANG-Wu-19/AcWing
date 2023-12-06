#include<iostream>

using namespace std;

int m,n;
int dx=0,dy=0;

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		dx+=a;
		dy+=b;
	}
	
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		x+=dx;
		y+=dy;
		cout<<x<<" "<<y<<endl;
	}	
}
