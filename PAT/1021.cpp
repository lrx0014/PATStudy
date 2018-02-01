///PAT 1021

#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 10000;
vector<int> G[maxn];
bool vis[maxn] = {false};
int maxdepth = 0;
int N;
set<int> deepestRoots;

void DFS(int u,int depth)
{
    if(maxdepth<depth)
    {
        maxdepth = depth;
        deepestRoots.clear();
        deepestRoots.insert(u+1);
    }else if(maxdepth==depth)
    {
        deepestRoots.insert(u+1);
    }
    vis[u] = true;
    for(int i=0;i<G[u].size();i++)
    {
        int t = G[u][i];
        if(!vis[t])
        {
            DFS(t,depth+1);
        }
    }
}

void DFSTrave(vector<int> *G)
{
    int Count = 0;
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            DFS(i,1);
            Count++;
        }
    }
    if(Count==1)
    {
        set<int>::iterator it = deepestRoots.begin();
        int s = *(it) - 1;
        maxdepth = 0;
        fill(vis,vis+maxn,false);
        set<int> deepestRootstemp = deepestRoots;
        deepestRoots.clear();
        DFS(s,1);
        it = deepestRootstemp.begin();
        for(it;it!=deepestRootstemp.end();it++)
        {
            deepestRoots.insert(*(it));
        }
        it = deepestRoots.begin();
        for(it;it!=deepestRoots.end();it++)
        {
            printf("%d\n",*it);
        }
    }else{
        printf("Error: %d components\n", Count);
    }
}

int main()
{
    scanf("%d",&N);
    int u,v;
    if(N==1)
    {
        printf("1\n");
    }
    for(int i=0;i<N-1;i++)
    {
        scanf("%d%d",&u,&v);
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }
    DFSTrave(G);
}
