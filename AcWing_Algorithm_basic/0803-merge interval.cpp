#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;
vector<pii> nums,res;

int main(){
    int n,l,r;
    int st=-2e9,ed=-2e9;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        nums.push_back({l,r});
    }
    
    sort(nums.begin(),nums.end());
    
    for(auto num:nums){
        if(ed<num.first){
            if(ed!=-2e9) res.push_back({st,ed});
            st=num.first,ed=num.second;
        }
        else if(ed<num.second) ed=num.second;
    }
    
    res.push_back({st,ed});
    
    cout<<res.size()<<endl;
    return 0;
}
