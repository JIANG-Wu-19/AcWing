#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 60;

int n;
int h[N];
int up[N], down[N];

bool dfs(int depth, int u, int su, int sd)
{
    // ����������и��� + �½����и��� > �ܸ��������ޣ������
    if (su + sd > depth) return false;
    if (u == n) return true;

    // ö�ٷŵ������������е����
    bool flag = false;
    for (int i = 1; i <= su; i ++ )
        if (up[i] < h[u])
        {
            int t = up[i];
            up[i] = h[u];
            if (dfs(depth, u + 1, su, sd)) return true;
            up[i] = t;
            flag = true;
            break;  // ע��������֤����̰��ԭ��ֻҪ�ҵ���һ�����Էŵ����У��Ϳ��Խ���ѭ����
        }
    if (!flag)  // ������ܷŵ�����һ�����к��棬�򵥿�һ���µ�����
    {
        up[su + 1] = h[u];
        if (dfs(depth, u + 1, su + 1, sd)) return true;
    }

    // ö�ٷŵ��½��������е����
    flag = false;
    for (int i = 1; i <= sd; i ++ )
        if (down[i] > h[u])
        {
            int t = down[i];
            down[i] = h[u];
            if (dfs(depth, u + 1, su, sd)) return true;
            down[i] = t;
            flag = true;
            break;  // ע��������֤����̰��ԭ��ֻҪ�ҵ���һ�����Էŵ����У��Ϳ��Խ���ѭ����
        }
    if (!flag)  // ������ܷŵ�����һ�����к��棬�򵥿�һ���µ�����
    {
        down[sd + 1] = h[u];
        if (dfs(depth, u + 1, su, sd + 1)) return true;
    }

    return false;
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i ++ ) cin >> h[i];

        int depth = 0;
        while (!dfs(depth, 0, 0, 0)) depth ++ ;     // ������������

        cout << depth << endl;
    }

    return 0;
}

