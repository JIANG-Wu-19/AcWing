#include<iostream>

using namespace std;

char isbn[14];
int num[10];


int main(){
    cin>>isbn;
    int j=0;
    for(int i=0;i<13;i++){
        if(isbn[i]-'0'>=0&&isbn[i]-'0'<10){
            num[j++]=isbn[i]-'0';
        }
        if(isbn[i]=='X'){
            num[9]=10;
        }
    }
    
    int sum=0;
    
    for(int i=0;i<9;i++){
        sum+=num[i]*(i+1);
    }
    
    int remain=sum % 11;
    
    if(remain==num[9]){
        cout<<"Right"<<endl;
    }else{
        if(remain==10){
            isbn[12]='X';
            for(int i=0;i<13;i++){
                cout<<isbn[i];
            }
            cout<<endl;
        }else{
            isbn[12]=remain+'0';
            for(int i=0;i<13;i++){
                cout<<isbn[i];
            }
            cout<<endl;
        }
    }
}
