#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define mem(a, b) memset(a, b, sizeof(a))
struct bign {
    int ilen;     //整数部分的长度
    int flen;     //小数部分的长度
    int in[1010]; //整数部分数字
    int fn[1010]; //小数部分数字
    bign() {
        ilen = 0, flen = 0;
        mem(in, 0), mem(fn, 0);
    }
};
//让2个浮点数的小数部分长度相同
void cmp(string& a, string& b) {
    int lena = a.length(), lenb = b.length();
    int posa = a.find('.'), posb = b.find('.');
    lena -= posa, lenb -= posb;
    lena < lenb ? a.append(lenb - lena, '0') : b.append(lena - lenb, '0');
}
//将字符串转换为大整数
bign change(string s) {
    bign c;
    int len = s.length();
    int pos = s.find('.');
    _for(i, 0, len) {
        if (i == pos)
            continue;
        i < pos ? c.in[c.ilen++] = s[pos - i - 1] - '0' : c.fn[c.flen++] = s[len - i +
                                   pos] - '0';
    }
    return c;
}
//高精度a + b
bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    //对小数部分进行处理
    _for(i, 0, a.flen) {
        int tmp = a.fn[i] + b.fn[i] + carry;
        c.fn[c.flen++] = tmp % 10;
        carry = tmp / 10;
    }
    //对整数部分进行处理
    _for(i, 0, max(a.ilen, b.ilen)) {
        int tmp = a.in[i] + b.in[i] + carry;
        c.in[c.ilen++] = tmp % 10;
        carry = tmp / 10;
    }
    if (carry != 0) {
        c.in[c.ilen++] = carry;
    }
    return c;
}
//输出bign
void print(bign a) {
    //打印整数部分
    for (int i = a.ilen - 1; i >= 0; --i) {
        printf("%d", a.in[i]);
    }
    //打印小数点
    printf(".");
    //打印小数部分
    for (int i = a.flen - 1; i >= 0; --i) {
        printf("%d", a.fn[i]);
    }
    printf("\n");
}
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        cmp(s1, s2);
        bign a = change(s1), b = change(s2);
        print(add(a, b));
    }
    return 0;
}
