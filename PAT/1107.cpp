/// PAT 1107

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Father,isRoot;

int cmp(int a,int b)
{
    return a>b;
}

int findFather(int x)
{
    int a = x;
    while(x!=Father[x])
    {
        x = Father[x];
    }
    while(a!=Father[a])
    {
        int z = a;
        a = Father[a];
        Father[z] = x;
    }
    return x;
}

void Union(int a,int b)
{
    int FaA = findFather(a);
    int FaB = findFather(b);
    if(FaA!=FaB)
    {
        Father[FaA] = FaB;
    }
}


int main()
{
    int n,k,t,cnt=0;
    int hobbies[1001] = {0};
    scanf("%d",&n);
    Father.resize(n+1);
    isRoot.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        Father[i] = i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d:",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&t);
            if(hobbies[t]==0)
            {
                hobbies[t]=i;
            }
            Union(i,findFather(hobbies[t]));
        }
    }
    for(int i=1;i<=n;i++)
    {
        isRoot[findFather(i)]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(isRoot[i]!=0)
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    sort(isRoot.begin(),isRoot.end(),cmp);
    for(int i=0;i<cnt;i++)
    {
        printf("%d",isRoot[i]);
        if(i!=cnt-1)
        {
            printf(" ");
        }
    }
}

