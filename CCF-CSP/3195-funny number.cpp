#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1010;

ll states[N][7];

int main(){
    ll mod = 1e9+7;
    ll n;
    cin>>n;

    for(ll i =0;i<6;i++)
        states[0][i]=0;
    /*6╓╓╫┤╠м
     * 0гнгн╩г013
     * 1гнгн╩г13
     * 2гнгн╩г01
     * 3гнгн╩г3
     * 4гнгн╩г1
     * 5гнгн╬▐
    */
    for(ll i=1;i<=n;i++)
    {
        ll j = i-1;
        states[i][0] = 1;
        states[i][1] = (states[j][0] + states[j][1] * 2) % mod;
        states[i][2] = (states[j][0] + states[j][2]) % mod;
        states[i][3] = (states[j][1] + states[j][3] * 2) % mod;
        states[i][4] = (states[j][1] + states[j][2] + states[j][4] * 2) % mod;
        states[i][5] = (states[j][3] + states[j][4] + states[j][5] * 2) % mod;
    }
    cout<<states[n][5]<<endl;
    return 0;
}
