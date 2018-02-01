/// PAT 1033
/*
��̰���㷨��̰��˼·���£�
���ȶ��������ݰ������������򣬴�Aվ�㿪ʼ���Ǽ����ͺ������ʻ����Ϊmax, ��Aվ�㵽A+max������������
1. ����������һ���ͼ�С��A��վ�㣬����A������Ϊ�պñ�֤�ܴ�A�ߵ���վ�㡣
2. ��û��1�����վ�㵫�����յ㣬��A������Ϊ�պñ�֤�ܴ�A�ߵ����յ㡣
3. ������1,2������Ǵ˷�Χ���б�ļ���վ������A�������ߵ���Щվ�����ͼ���͵�һ����
4. ����1,2,3������϶����ڴ˷�ΧΪû���κ�վ�㣬�������ʻ����ΪA+max.
ע�⣺�и�case�����壬û�о���Ϊ0��վ�㣬�������޷���ʻ��������һ����������ע���¼ʣ��������
�����е���ĳ����վʱ������ܻ��ж�����ɣ����¸���վһ�����꣩�����յ�ʱ����һ��û�͡�
����Ĳ������ݲ��ϣ���2ʱ������Ҳ��ͨ����
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Node{
    int dis;
    float price;
}Station;

bool cmp(Station sta1,Station sta2)
{
    if(sta1.dis<sta2.dis)
    {
        return true;
    }else{
        return false;
    }
}

int main()
{
    Station sta[512];
    float cmax,end_dis,perunit;
    int sta_nums;
    cin>>cmax>>end_dis>>perunit>>sta_nums;
    float sta_dis,sta_price;
    for(int i=0;i<sta_nums;i++)
    {
        cin>>sta[i].price>>sta[i].dis;
    }
    sta[sta_nums].price = 0;
    sta[sta_nums].dis = end_dis;
    sort(sta,sta+sta_nums,cmp);
    if(sta[0].dis!=0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    float maxFuel = cmax*perunit;
    float leftFuel;
    int cur_index = 0;
    float cost = 0;
    int cur = 0;
    while(sta[cur_index].dis<end_dis)
    {
        float cur_cheaper = -1;
        int cheaper = -1;
        int fstindex = -1;
        for(int i=cur+1;i<=sta_nums&&sta[i].dis-sta[cur].dis<=maxFuel;i++)
        {
            if(cur_cheaper==-1 || sta[i].price<cur_cheaper)
            {
                cur_cheaper = sta[i].price;
                cheaper = i;
            }
            if(fstindex==-1 && sta[i].price<sta[cur].price)
            {
                fstindex = i;
            }
        }
        if(cheaper==-1 && fstindex==-1)
        {
            break;
        }
        if(fstindex==-1)
        {
            if(end_dis-sta[cur].dis<=maxFuel)
            {
                cost += ((end_dis-sta[cur].dis)/perunit-leftFuel)*sta[cur].price;
                leftFuel = 0;
                cur = sta_nums;
            }else{
                cost += (cmax-leftFuel)*sta[cur].price;
                leftFuel = cmax-(sta[cheaper].dis-sta[cur].dis)/perunit;
                cur = cheaper;
            }
        }else{
            cost += ((sta[fstindex].dis-sta[cur].dis)/perunit-leftFuel)*sta[cur].price;
            leftFuel = 0;
            cur = fstindex;
        }
    }
    if(sta[cur].dis==end_dis)
    {
        printf("%.2lf\n",cost);
    }else{
        printf("The maximum travel distance = %.2lf\n",sta[cur].dis+maxFuel);
    }
}
