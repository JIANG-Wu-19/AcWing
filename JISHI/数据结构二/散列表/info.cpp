#include<bits/stdc++.h>

using namespace std;

struct student
{
    string name;
    string sex;
    int age;
};

unordered_map<string,student> umap;

int main()
{
    int n,m;
    while(cin>>n){
        for(int i=0;i<n;i++){
            string index,name,sex;
            int age;
            cin>>index>>name>>sex>>age;
            student s;
            s.name=name;
            s.sex=sex;
            s.age=age;
            umap[index]=s;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            string index;
            cin>>index;
            if(umap.find(index)!=umap.end()){
                student s=umap[index];
                cout<<index<<" "<<s.name<<" "<<s.sex<<" "<<s.age<<endl;
            }
            else{
                cout<<"No Answer!"<<endl;
            }
        }
    }
}
