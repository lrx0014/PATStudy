/// PAT 1033
/*
用贪心算法：贪心思路如下：
首先对输入数据按距离升序排序，从A站点开始，记加满油后最大行驶距离为max, 从A站点到A+max距离内搜索：
1. 若搜索到第一个油价小于A的站点，则在A加油量为刚好保证能从A走到该站点。
2. 若没有1里面的站点但是有终点，则A加油量为刚好保证能从A走到该终点。
3. 若不是1,2情况但是此范围内有别的加油站，则在A加满油走到那些站点中油价最低的一个。
4. 不是1,2,3情况，肯定是在此范围为没有任何站点，则最大行驶距离为A+max.
注意：有个case是陷阱，没有距离为0的站点，则汽车无法行驶。油量不一定是整数！注意记录剩余油量！
过程中到达某个油站时油箱可能会有多余的由（到下个油站一定用完），而终点时油箱一定没油。
此题的测试数据不严，就2时加满油也能通过。
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
