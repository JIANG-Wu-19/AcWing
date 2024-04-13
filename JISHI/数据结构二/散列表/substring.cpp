#include<bits/stdc++.h>

using namespace std;

int main() {

    string str;
    while (cin >> str) {
        map<string, int> substring;
        for (int i = 0; i < str.size(); i++) {
            for (int j = 0; j < i; j++) {
                string key = str.substr(j, i - j);
                substring[key]++;
            }
        }
        map<string, int>::iterator it;

        for (it = substring.begin(); it != substring.end(); it++) {
            if (it->second > 1) {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
    return 0;


}
