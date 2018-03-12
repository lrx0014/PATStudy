/// PAT 1134

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    vector<int> v[N];
    int a,b;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    int k;
    int nv;
    scanf("%d",&k);
    int cnt = 0;
    bool answer[k];
    for(int i=0;i<k;i++)
    {
        scanf("%d",&nv);
        int flag = 0;
        vector<int> Hash(M,0);
        for(int j=0;j<nv;j++)
        {
            int num;
            scanf("%d",&num);
            for(int t=0;t<v[num].size();t++)
            {
                Hash[v[num][t]] = 1;
            }
        }
        for(int j=0;j<M;j++)
        {
            if(Hash[j]==0)
            {
                //printf("No\n");
                answer[cnt++] = false;
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            //printf("Yes\n");
            answer[cnt++] = true;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        if(answer[i]==true)
        {
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}
