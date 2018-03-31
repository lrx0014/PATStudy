/***********************************************************************************************************
C国由n个小岛组成，为了方便小岛之间联络，C国在小岛间建立了m座大桥，每座大桥连接两座小岛。
两个小岛间可能存在多座桥连接。然而，由于海水冲刷，有一些大桥面临着不能使用的危险。
如果两个小岛间的所有大桥都不能使用，则这两座小岛就不能直接到达了。
然而，只要这两座小岛的居民能通过其他的桥或者其他的小岛互相到达，他们就会安然无事。
但是，如果前一天两个小岛之间还有方法可以到达，后一天却不能到达了，居民们就会一起抗议。
现在C国的国王已经知道了每座桥能使用的天数，超过这个天数就不能使用了。现在他想知道居民们会有多少天进行抗议。
输入格式
　　输入的第一行包含两个整数n, m，分别表示小岛的个数和桥的数量。
　　接下来m行，每行三个整数a, b, t，分别表示该座桥连接a号和b号两个小岛，能使用t天。小岛的编号从1开始递增。
输出格式
　　输出一个整数，表示居民们会抗议的天数。
样例输入
4 4
1 2 2
1 3 2
2 3 1
3 4 3
样例输出
2
样例说明
　　第一天后2和3之间的桥不能使用，不影响。
　　第二天后1和2之间，以及1和3之间的桥不能使用，居民们会抗议。
　　第三天后3和4之间的桥不能使用，居民们会抗议。
***********************************************************************************************************/

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int father[10005];

struct island
{
    int x,y,t;
}e[10005];

bool cmp(island a,island b)
{
    return a.t > b.t;
}

int Find(int x)
{
    return father[x]==x?x:father[x]=Find(father[x]);
}

bool Union(int x,int y)
{
    int tx = Find(x);
    int ty = Find(y);
    if(tx == ty)
    {
        return false;
    }
    father[tx] = ty;
    return true;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].t);
    }
    sort(e,e+m,cmp);
    for(int i=0;i<=n;i++)
    {
        father[i] = i;
    }
    int cnt = 0;
    int lastDay = -1;
    for(int i=0;i<m;i++)
    {
        if(Union(e[i].x,e[i].y) && lastDay!=e[i].t)
        {
            cnt ++;
            lastDay = e[i].t;
        }
    }
    printf("%d\n",cnt);
}

