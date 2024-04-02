#include <iostream>
#include <cstdio>
#include <algorithm>
/*
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
50 1300 12 2
7.10 0
7.00 600

749.17
The maximum travel distance = 1200.00
*/
using namespace std;
/*
���� :
����ÿ���������һ�а���4��������Cmax��<=100��������������������D��<=30000����
�����ݵ�Ŀ�ĵس��еľ��룻Davg��<=20����������ÿ��λ���Ϳ���ʻ��ƽ�����룻N��<=500����
������վ��������������N�У�ÿ�а���һ�ԷǸ�����Pi��ú�����ۣ�Di��<=D�������վ�����ݵľ��룬i=1����N��һ���е����������ÿո������

��� :
����ÿ������������һ�д�ӡ����˵ļ۸񣬾�ȷ��С�����2λ��
���迪ʼʱ�����ǿյġ�����޷�����Ŀ�ĵأ����ӡ�������ʻ����=X����
����X�ǳ���������ʻ�������ܾ��룬��ȷ��С�����2λ��
*/
struct GasStation {
    double price;
    int distance;
};

bool ComparePrice(GasStation x, GasStation y) {
    return x.price < y.price;
}

int main() {
    int cmax, d, davg,
        n; // cmax : ����������, d : �ݵ�Ŀ�ĵس��еľ���, davg : ��ÿ��λ���Ϳ���ʻ��ƽ������, n : ����վ����;
    while (cin >> cmax >> d >> davg >> n) {
        double currentprice = 0; // ��ǰ�ͷ�

        bool tag[d + 1]; // ��¼��ǰ���Ķε�·�ǴӼ���վ�������ߵ�
        GasStation gasStation[n];

        for (int i = 1; i <= d; ++i) tag[i] = false;
        for (int i = 0; i < n;
                ++i) cin >> gasStation[i].price >> gasStation[i].distance;

        sort(gasStation, gasStation + n, ComparePrice); // ���ͼ۰�������

        for (int i = 0; i < n;
                ++i) {  // ��tag[]���м�¼, ��ͬʱ����� currentprice
            int currentdistance = 0; // ��¼���������վ����Ҫ�����͵ľ���
            for (int j = gasStation[i].distance + 1;
                    j <= gasStation[i].distance + cmax * davg; ++j) {
                if (tag[j] == false) { // ��� tag[j]Ϊ�������
                    tag[j] = true;
                    currentdistance++;
                }
                if (j == d || j == gasStation[i].distance + cmax * davg) { // �ߵ��˾�ͷ
                    currentprice += gasStation[i].price  * currentdistance / (davg * 1.0);
                    break;
                }
            }
        }

        int fill = 1; // tag[]�Ƿ�ȫΪ��ı�־λ
        double journey = 0;
        for (int i = 1; i <= d; ++i) {
            if (tag[i] == true) journey++;
            else {
                fill = 0;
                break;
            }
        }

        if (fill) printf("%.2f\n", currentprice);
        else printf("The maximum travel distance = %.2f\n", journey);
    }
    return 0;
}
