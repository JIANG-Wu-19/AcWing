#include <iostream>
#include <algorithm>
#define l first
#define r second
using namespace std;
typedef pair <int,int> PII;
const int N = 5010;
int n;
PII a[N];
int f[N];
int main () {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i].first >> a[i].second;
    sort (a + 1,a + 1 + n,[](PII x,PII y) {
        return x.l < y.l;
    });
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        f[i] = 1;
        for (int j = 1;j < i;j++) {
            if (a[j].r < a[i].r) f[i] = max (f[i],f[j] + 1);
        }
        ans = max (ans,f[i]);
    }
    cout << ans << endl;
    return 0;
}

