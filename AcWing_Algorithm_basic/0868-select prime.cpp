#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

//primes���������������
int primes[N], cnt;
//st[i], iΪ������Ϊfalse����Ϊtrue
bool st[N];

void get_primes(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) primes[cnt++] = i;
        //����primes[0]Ϊn��С��������,iΪ����������
        //��֪��primes[i]��i>0,������ѭ�����������ı�ǡ�
        for(int j = 0; primes[j] <= n / i; j ++)
        {
            //���;primes[j]һ����primes[j]*i����С������
            st[primes[j]*i] = true;
            //����primes[j]һ����i����С������,û�б�Ҫ�ٱ���,primesҪС�ڵ���i����С������
            //�����ܱ�֤ÿ��������һ��,��û���ظ�
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
    return 0;
}
