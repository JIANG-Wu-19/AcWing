#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    // for(int x=0;x<=100;x++){
    //     for(int y=0;y<=100;y++){
    //         for(int z=0;z<=100;z++){
    //             if(x+y+z==100&&5*x+3*y+1.0/3*z<=n){
    //                 cout<<"x="<<x<<",y="<<y<<",z="<<z<<endl;
    //             }
    //         }
    //     }
    // }

    for(int x=0;x<=100;x++){
        for(int y=0;y<=100-x;y++){
            for(int z=0;z<=100-x-y;z++){
                if(x+y+z==100&&5*x+3*y+1.0/3*z<=n){
                    cout<<"x="<<x<<",y="<<y<<",z="<<z<<endl;
                }
            }
        }
    }

    return 0;
}
