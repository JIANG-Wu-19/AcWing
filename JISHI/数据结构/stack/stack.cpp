#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n;
	string str,data;

	while(cin>>n){
		stack<string> s;
		for(int i = 0; i < n; i++){
			cin>>str;
			if(str == "P"){
				cin>>data;
				s.push(data);
			}
			else if(str == "A"){
				if(s.empty())
					cout<<'E'<<endl;
				else{
	//				char tmp = ;
					cout<<s.top()<<endl;
				}

			}
			else if(str == "O"){
				if(!s.empty()){
					s.pop();
				}
			}
		}
	}


}

