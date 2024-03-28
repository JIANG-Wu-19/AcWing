#include <iostream>
using namespace std;

const int N = 85;

int num[N] = {0};

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        if (num[0] != num[1]) {
            cout << "0 ";
        }

        for (int i = 1; i < n - 1; i++) {
            if ((num[i - 1] > num[i] && num[i + 1] > num[i]) || (num[i - 1] < num[i] &&
                    num[i + 1] < num[i])) {
                cout << i << " ";
            }
        }

        if(num[n-1]!=num[n-2]){
            cout<<n-1<<endl;
        }else{
            cout<<endl;
        }
    }

    return 0;

}
