/*
 * Project: 11_��ϣ��
 * File Created:Sunday, January 17th 2021, 4:39:01 pm
 * Author: Bug-Free
 * Problem:AcWing 840. ģ��ɢ�б�  ����Ѱַ��
 */
#include <cstring>
#include <iostream>

using namespace std;

//����Ѱַ��һ�㿪 ���ݷ�Χ�� 2~3��, ��������ʾ�û�г�ͻ��
const int N = 2e5 + 3;        //�������ݷ�Χ�ĵ�һ������
const int null = 0x3f3f3f3f;  //�涨��ָ��Ϊ null 0x3f3f3f3f

int h[N];

int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) {
            t = 0;
        }
    }
    return t;  //������λ���ǿյ�, �򷵻ص�����Ӧ�ô洢��λ��
}

int n;

int main() {
    cin >> n;

    memset(h, 0x3f, sizeof h);  //�涨��ָ��Ϊ 0x3f3f3f3f

    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I") {
            h[find(x)] = x;
        } else {
            if (h[find(x)] == null) {
                puts("No");
            } else {
                puts("Yes");
            }
        }
    }
    return 0;
}
