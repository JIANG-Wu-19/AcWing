#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5+5,P = 131;//131 13331
ULL h[N],p[N];

// h[i]ǰi���ַ���hashֵ
// �ַ������һ��p�������֣��������ַ�+˳����Ҫȷ����ͬ���ַ�����Ӧ��ͬ������
// P = 131 ��  13331 Q=2^64����99%������²�����ֳ�ͻ
// ʹ�ó����� �����ַ������Ӵ��Ƿ���ͬ
ULL query(int l,int r){
    return h[r] - h[l-1]*p[r-l+1];
}
int main(){
    int n,m;
    cin>>n>>m;
    string x;
    cin>>x;

    //�ַ�����1��ʼ��ţ�h[1]Ϊǰһ���ַ��Ĺ�ϣֵ
    p[0] = 1;
    h[0] = 0;
    for(int i=0;i<n;i++){
        p[i+1] = p[i]*P;            
        h[i+1] = h[i]*P +x[i];      //ǰ׺���������ַ����Ĺ�ϣֵ
    }

    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(query(l1,r1) == query(l2,r2)) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
