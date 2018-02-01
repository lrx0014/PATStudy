#include <stdio.h>
#define MAX_required 505
#define Max_int 0x7fffffff

int citymap[MAX_required][MAX_required];
int callnum[MAX_required];


typedef struct  CITY
{
    int dist;
    int visited;
    int number;
    int call;
} _CITY;

_CITY city[MAX_required];


void Dijkstra(int start, int end,int n)
{

    for (int i = 0; i < n; i++)
    {
        city[i].dist = Max_int;
        city[i].visited = 0;
        city[i].number = 0;
        city[i].call = 0;
    }

    city[start].dist = 0;
    city[start].number = 1;
    city[start].call = callnum[start];

    for (int cnt = 0; cnt < n; cnt++)
    {
        int Min = Max_int, pos = -1;
        for (int i = 0; i < n; i++)
        {
            if ((city[i].visited == 0) && (city[i].dist < Min))
            {
                Min = city[i].dist;
                pos = i;
            }
        }


        if (pos == -1)
            break;

        city[pos].visited = 1;

        for (int j = 0; j < n; j++)
        {
            if ((city[j].visited == 0) && (citymap[pos][j] != Max_int))
            {
                if (city[j].dist>city[pos].dist + citymap[pos][j])
                {
                    city[j].dist = city[pos].dist + citymap[pos][j];
                    city[j].number = city[pos].number;
                    city[j].call = city[pos].call+callnum[j];
                }
                else if (city[j].dist==(city[pos].dist + citymap[pos][j]))
                {
                    city[j].number += city[pos].number;
                    if (city[j].call < city[pos].call + callnum[j])
                        city[j].call = city[pos].call + callnum[j];
                }
            }
        }
    }


    printf("%d %d",city[end].number,city[end].call);
}


int main()
{
    int n, m, start, end;
    scanf("%d%d%d%d",&n,&m,&start,&end);
    for (int i = 0; i<n; i++)
        scanf("%d",&callnum[i]);
    int a, b, l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            citymap[i][j] = Max_int;
        }
    }
    for (int i = 0; i<m; i++)
    {
        scanf("%d%d%d",&a,&b,&l);
        citymap[a][b] = l;
        citymap[b][a] = l;
    }

    Dijkstra(start, end, n);
    return 0;
}
