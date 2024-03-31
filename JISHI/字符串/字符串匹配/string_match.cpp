#include<iostream>
#include<vector>
using namespace std;
void trans(string &str) {
    //全部转换为小写
    for (int i = 0; i < str.size(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
}
int main()
{
    std::ios::sync_with_stdio(false);
    string str, patern;
    int n;
    vector<string> vec;
    cin >> n;
    while (n--) {
        cin >> str;
        vec.push_back(str);
    }
    cin >> patern;
    trans(patern);
    for (int i = 0; i < vec.size(); ++i) {
        str = vec[i];
        trans(str);
        int a = 0, b = 0;
        while (a < str.size() && b < patern.size()) {
            if (str[a] == patern[b]) {
                a++;
                b++;
            }
            else if (patern[b] == '[') {
                int pos = patern.find(str[a],b);
                if (pos != string::npos) {
                    b = patern.find(']', pos) + 1;
                    a++;
                }
                else
                    break;
            }
            else
                break;
        }
        if (a == str.size() && b == patern.size())
            cout << i + 1 << " " << vec[i] << endl;
    }
}

