/*******************************************************************************
问题描述
    抗日战争时期，冀中平原的地道战曾发挥重要作用。
    地道的多个站点间有通道连接，形成了庞大的网络。但也有隐患，
    当敌人发现了某个站点后，其它站点间可能因此会失去联系。
    我们来定义一个危险系数DF(x,y)：
    对于两个站点x和y (x != y), 如果能找到一个站点z，当z被敌人破坏后，x和y不连通，
    那么我们称z为关于x,y的关键点。相应的，对于任意一对站点x和y，
    危险系数DF(x,y)就表示为这两点之间的关键点个数。
    本题的任务是：已知网络结构，求两站点之间的危险系数。
输入格式
    输入数据第一行包含2个整数n(2 <= n <= 1000), m(0 <= m <= 2000),分别代表站点数，通道数；
    接下来m行，每行两个整数 u,v (1 <= u, v <= n; u != v)代表一条通道；
    最后1行，两个数u,v，代表询问两点之间的危险系数DF(u, v)。
输出格式
    一个整数，如果询问的两点不连通则输出-1.
样例输入
    7 6
    1 3
    2 3
    3 4
    3 5
    4 5
    5 6
    1 6
样例输出
    2
********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int father[1000];
int cnt,lene,start,End,n,m;

struct node
{
    int x,y;
}e[1000];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        father[i] = i;
    }
}

int Find(int x)
{
    return father[x]==x?x:Find(father[x]);
}

void Union(int x,int y)
{
    int tx = Find(x);
    int ty = Find(y);
    if(tx != ty)
    {
        if(tx < ty)
        {
            father[ty] = tx;
        }
        else
        {
            father[tx] = ty;
        }
    }
}

bool solve()
{
    init(n);
    for(int i=0;i<lene;i++)
    {
        Union(e[i].x,e[i].y);
    }

    if(Find(start) != Find(End))
    {
        return false;
    }

    cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(i!=start && i!=End)
        {
            init(n);
            for(int j=0;j<lene;j++)
            {
                int tx = e[j].x;
                int ty = e[j].y;
                if(tx!=i && ty!=i)
                {
                    Union(tx,ty);
                }
            }
            if(Find(start) != Find(End))
            {
                cnt ++;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    lene = 0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&e[i].x,&e[i].y);
        lene ++;
    }
    scanf("%d%d",&start,&End);
    if(solve())
    {
        printf("%d\n",cnt);
    }else{
        printf("%d\n",-1);
    }
}
