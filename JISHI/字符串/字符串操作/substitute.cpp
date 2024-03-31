#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> split(string& s) {
    int i = 0, j = 0;
    vector<string> a;
    while (i < s.size()) {
        while (s[j] != ' ' && j < s.size())
            ++j;
        a.push_back(s.substr(i, j - i));
        while (s[j] == ' ')
            ++j;
        i = j;
    }
    return a;
}

int main() {
    string s, a, b;
    getline(cin, s);
    cin >> a >> b;
    auto res = split(s);
    for (int i = 0; i < res.size(); ++i)
        if (res[i] == a)
            cout << b << ' ';
        else
            cout << res[i] << ' ';
    return 0;
}
