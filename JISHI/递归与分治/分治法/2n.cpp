#include<bits/stdc++.h>

using namespace std;

void pow2(int n) {
    vector<int> bi;
    while (n) {
        bi.push_back(n % 2);
        n /= 2;
    }
    vector<int> pos;
    for (int i = bi.size() - 1; i >= 0; i--) {
        if (bi[i] == 1) {
            pos.push_back(i);
        }
    }
    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] == 0) {
            cout << "2(0)";
        } else if (pos[i] == 1) {
            cout << "2";
        } else if (pos[i] == 2) {
            cout << "2(2)";
        } else if (pos[i] > 2) {
            cout << "2(";
            pow2(pos[i]);
            cout << ")";
        }
        if (i != pos.size() - 1) {
            cout << "+";
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        pow2(n);
        cout << endl;
    }
}
