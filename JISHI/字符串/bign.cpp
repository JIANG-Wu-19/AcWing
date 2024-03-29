#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define mem(a, b) memset(a, b, sizeof(a))
struct bign {
    int ilen;     //�������ֵĳ���
    int flen;     //С�����ֵĳ���
    int in[1010]; //������������
    int fn[1010]; //С����������
    bign() {
        ilen = 0, flen = 0;
        mem(in, 0), mem(fn, 0);
    }
};
//��2����������С�����ֳ�����ͬ
void cmp(string& a, string& b) {
    int lena = a.length(), lenb = b.length();
    int posa = a.find('.'), posb = b.find('.');
    lena -= posa, lenb -= posb;
    lena < lenb ? a.append(lenb - lena, '0') : b.append(lena - lenb, '0');
}
//���ַ���ת��Ϊ������
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
//�߾���a + b
bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    //��С�����ֽ��д���
    _for(i, 0, a.flen) {
        int tmp = a.fn[i] + b.fn[i] + carry;
        c.fn[c.flen++] = tmp % 10;
        carry = tmp / 10;
    }
    //���������ֽ��д���
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
//���bign
void print(bign a) {
    //��ӡ��������
    for (int i = a.ilen - 1; i >= 0; --i) {
        printf("%d", a.in[i]);
    }
    //��ӡС����
    printf(".");
    //��ӡС������
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
