#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

unordered_map <string,int> umap;
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string x="";
		for(int j=1;j<=8;j++){
			string str;
			cin>>str;
			x+=str;
		}
		umap[x]++;
		cout<<umap[x]<<endl;
	}
	
	return 0;
}


