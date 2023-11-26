#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;
int h[N];   //��
int ph[N];  //��ŵ�k���������±�
int hp[N];  //��Ŷ��е�Ĳ������
int cur_size;   //size ��¼���Ƕѵ�ǰ�����ݶ���

//�������������ʵ����ôЩ�� ���ؼ������ ���hp[u]=k ��ph[k]=u ��ӳ���ϵ
//֮����Ҫ���������Ĳ�������Ϊ ����һϵ�в��� ���е�Ԫ�ز����ᱣ��ԭ�еĲ���˳��
//�Ӷ�������Ҫ��Ӧ��ԭ�ȵ�K������Ԫ��
//���������ԭ�� ��ô����������ʵ����������˳���ǿ��Ի��� 
//h,hp,ph֮����������ӳ���ϵ ���Խ���˳��Ĳ�ͬ�Խ�����������Ӱ��
void heap_swap(int u,int v)
{   
    swap(h[u],h[v]); 
     swap(hp[u],hp[v]);     
     swap(ph[hp[u]],ph[hp[v]]);            

}

void down(int u)
{
    int t=u;
    if(u*2<=cur_size&&h[t]>h[u*2]) t=u*2;
    if(u*2+1<=cur_size&&h[t]>h[u*2+1])  t=u*2+1;
    if(u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}
void up(int u)
{
    if(u/2>0&&h[u]<h[u/2]) 
    {
        heap_swap(u,u/2);
        up(u>>1);
    }
}

int main()
{
    int n;
    cin>>n;
    int m=0;      //m������¼��������ĸ���
                //ע��m��������cur_size�ǲ�ͬ�� cur_size�Ǽ�¼���е�ǰ���ݵĶ���
                //��Ӧ���� m����hp��Ӧ�ô��ֵ
    while(n--)
    {
        string op;
        int k,x;
        cin>>op;
        if(op=="I")
        {
            cin>>x;
            m++;
            h[++cur_size]=x;
            ph[m]=cur_size;
            hp[cur_size]=m;
            //down(size);
            up(cur_size);
        }
        else if(op=="PM")    cout<<h[1]<<endl;
        else if(op=="DM")
        {
            heap_swap(1,cur_size);
            cur_size--;
            down(1);
        }
        else if(op=="D")
        {
            cin>>k;
            int u=ph[k];                //����һ��Ҫ��u=ph[k]�����k���������±�
            heap_swap(u,cur_size);          //��Ϊ�ڴ˴�heap_swap������ph[k]��ֵ�Ѿ����� 
            cur_size--;                    //�����up,down��������Ȼʹ��ph[k]��Ϊ�����ͻᷢ������
            up(u);
           down(u);
        }
        else if(op=="C")
        {
            cin>>k>>x;
            h[ph[k]]=x;                 //�˴�����δ�漰heap_swap�����������up��down����ֻ�ᷢ��һ������
            down(ph[k]);                //���Կ�ֱ�Ӵ���ph[k]��Ϊ����
            up(ph[k]);
        }

    }
    return 0;
}
