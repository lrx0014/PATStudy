/// PAT 1046

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    scanf("%d",&n);
    const int num = n + 1;
    int distance[num];
    distance[0] = 0;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        distance[i] = distance[i-1] + t;
    }
    scanf("%d",&m);
    int from,to;
    int ansers[m+1];
    for(int j=0;j<m;j++)
    {
        scanf("%d %d",&from,&to);
        if(from>to) swap(from,to);
        int a = distance[to-1] - distance[from-1];
        int b = distance[from-1] + distance[n] - distance[to-1];
        if(a<b) ansers[j] = a;
        else ansers[j] = b;
    }
    for(int x=0;x<m;x++)
    {
        printf("%d",ansers[x]);
        if(x<=m-2) printf("\n");
    }
}
