#include<iostream>
#include<algorithm>

const int N=15;

int n,m;

struct window{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};

window windows[N];

using namespace std;

int main(){
    int x,y;
    
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>windows[i].x1>>windows[i].y1>>windows[i].x2>>windows[i].y2;
        windows[i].num=i;
    }
    
    while(m--){
        cin>>x>>y;
        if(x>=windows[n].x1&&x<=windows[n].x2&&y>=windows[n].y1&&y<=windows[n].y2){
            cout<<windows[n].num<<endl;
            continue;
        }else{
            int p=0;
            for(int i=n-1;i>=1;i--){
                if(x>=windows[i].x1&&x<=windows[i].x2&&y>=windows[i].y1&&y<=windows[i].y2){
                    cout<<windows[i].num<<endl;
                    
                    // 直接交换是错误的
                    // swap(windows[i].x1,windows[n].x1);
                    // swap(windows[i].y1,windows[n].y1);
                    // swap(windows[i].x2,windows[n].x2);
                    // swap(windows[i].y2,windows[n].y2);
                    
                    window tmp=windows[i];
                    for(int j=i;j<n;j++){
                        windows[j]=windows[j+1];
                    }
                    windows[n]=tmp;
                    p=1;
                    break;
                }
            }
            if(!p){
                cout<<"IGNORED"<<endl;
            }
        }
    }
    
    
    
}
