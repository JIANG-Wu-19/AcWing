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
输入 :
对于每种情况，第一行包含4个正数：Cmax（<=100），即油箱的最大容量；D（<=30000），
即杭州到目的地城市的距离；Davg（<=20），即汽车每单位汽油可行驶的平均距离；N（<=500），
即加油站总数。接下来是N行，每行包含一对非负数：Pi，煤气单价，Di（<=D），这个站到杭州的距离，i=1，…N。一行中的所有数字用空格隔开。

输出 :
对于每个测试用例，一行打印最便宜的价格，精确到小数点后2位。
假设开始时油箱是空的。如果无法到达目的地，请打印“最大行驶距离=X”，
其中X是车辆可以行驶的最大可能距离，精确到小数点后2位。
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
        n; // cmax : 箱的最大容量, d : 州到目的地城市的距离, davg : 车每单位汽油可行驶的平均距离, n : 加油站总数;
    while (cin >> cmax >> d >> davg >> n) {
        double currentprice = 0; // 当前油费

        bool tag[d + 1]; // 记录当前有哪段道路是从加油站出发能走的
        GasStation gasStation[n];

        for (int i = 1; i <= d; ++i) tag[i] = false;
        for (int i = 0; i < n;
                ++i) cin >> gasStation[i].price >> gasStation[i].distance;

        sort(gasStation, gasStation + n, ComparePrice); // 对油价按升序排

        for (int i = 0; i < n;
                ++i) {  // 对tag[]进行记录, 并同时计算出 currentprice
            int currentdistance = 0; // 记录从这个加油站出发要用其油的距离
            for (int j = gasStation[i].distance + 1;
                    j <= gasStation[i].distance + cmax * davg; ++j) {
                if (tag[j] == false) { // 如果 tag[j]为假则可走
                    tag[j] = true;
                    currentdistance++;
                }
                if (j == d || j == gasStation[i].distance + cmax * davg) { // 走到了尽头
                    currentprice += gasStation[i].price  * currentdistance / (davg * 1.0);
                    break;
                }
            }
        }

        int fill = 1; // tag[]是否全为真的标志位
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
