#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
bool isPrime[N];
vector<int> prime;

void Initial() {
    for (int i = 0; i < N; i++) {
        isPrime[i] = true;
    }

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i < N; i++) {
        if (!isPrime[i]) {
            continue;
        } else {
            prime.push_back(i);
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    Initial();

    int n;
    while (cin >> n) {
        bool output = false;
        for (int i = 0; i < prime.size() && prime[i] < n; i++) {
            if (prime[i] % 10 == 1) {
                if (!output) {
                    cout << prime[i];
                    output = true;
                } else {
                    cout << " " << prime[i];
                }
            }
        }
        if (!output) {
            cout << "-1" << endl;
        }
        cout << endl;
    }
}
