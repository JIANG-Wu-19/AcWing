#include<bits/stdc++.h>

using namespace std;

unordered_map<string,bool> isVisited;

struct str
{
    int num;
    string s;
    str(int num,string s):num(num),s(s){}
};

void bfs(string s)
{
    queue<str> q;
    q.push(str(0,s));
    isVisited[s]=true;
    while(!q.empty()){
        str current=q.front();
        q.pop();
        if(current.s.find("2012")!=string::npos){
            cout<<current.num<<endl;
            return;
        }
        for(int i=0;i<current.s.size()-1;i++){
            swap(current.s[i],current.s[i+1]);
            if(!isVisited[current.s]){
                q.push(str(current.num+1,current.s));
                isVisited[current.s]=true;
            }
            swap(current.s[i],current.s[i+1]);
        }
    }
    cout<<"-1"<<endl;
}

int main()
{
    int n;
    string s;
    while(cin>>n>>s){
        bfs(s);
    }
    return 0;
}
