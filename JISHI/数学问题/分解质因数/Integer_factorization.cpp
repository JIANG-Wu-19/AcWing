#include <iostream>
#include <cmath>
#include<vector>
using namespace std;

const int N = 31623;

bool isPrime[N];
vector<int> prime;

void init() {
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
    init();

    int n;
    while (cin >> n) {
        int num = 0;

        for (int i = 0; i < prime.size() && prime[i] < n; i++) {
            int factor = prime[i];
            while (n % factor == 0) {
                n /= factor;
                num++;
            }
        }
        if (n > 1) {
            num++;
        }
        cout << num << endl;
    }
}

//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 31623;
//
//bool isPrime[N];
//vector<int> prime;
//
//void init() {
//    for (int i = 0; i < N; i++) {
//        isPrime[i] = true;
//    }
//
//    isPrime[0] = false;
//    isPrime[1] = false;
//
//    for (int i = 2; i < N; i++) {
//        if (!isPrime[i]) {
//            continue;
//        } else {
//            prime.push_back(i);
//            for (int j = i * i; j < N; j += i) {
//                isPrime[j] = false;
//            }
//        }
//    }
//}
//
//int main() {
//    init();
//
//    int n;
//    while (cin >> n) {
//        int num = 0;
//        int i = 0;
//        while (i<prime.size()&&prime[i] < n) {
//
//            while (n % prime[i] == 0) {
//                n /= prime[i];
//                num++;
//            }
//            i++;
//
//        }
//        if (n > 1) {
//            num++;
//        }
//        cout << num << endl;
//    }
//}
