#include<iostream>
#include <vector>
#include <algorithm>
#define N  100010
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v1(n,0);
    for (int i = 0; i < n; i++)
        cin >> v1[i];

    vector<int> S(N,0);

    int res = 0;
    for (int i = 0,j = 0; i < n; i++)
    {
        S[v1[i]]++;
        while ( S[v1[i]] > 1) --S[v1[j++]];
        res = max(res, i - j + 1);
    }

    cout << res;

    return 0;
}
