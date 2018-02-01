/// PAT 1133

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Node{
    int address;
    int value;
    int next;
};

Node origin[100001];
vector<Node> ans;

int main()
{
    int start,n,k;
    scanf("%d %d %d",&start,&n,&k);
    for(int i=0;i<n;i++)
    {
        int addr,val,next;
        scanf("%d %d %d",&addr,&val,&next);
        origin[addr].address = addr;
        origin[addr].value = val;
        origin[addr].next = next;
    }

    int cur = start;

    while(cur != -1)
    {
        int value = origin[cur].value;
        if(value<0)
        {
            ans.push_back(origin[cur]);
        }
        cur = origin[cur].next;
    }

    cur = start;
    while(cur != -1)
    {
        int value = origin[cur].value;
        if(value>=0 && value<=k)
        {
            ans.push_back(origin[cur]);
        }
        cur = origin[cur].next;
    }

    cur = start;
    while(cur != -1)
    {
        int value = origin[cur].value;
        if(value>k)
        {
            ans.push_back(origin[cur]);
        }
        cur = origin[cur].next;
    }

    int i;
    for(i=0;i<ans.size()-1;i++)
    {
        printf("%05d %d %05d\n",ans[i].address,ans[i].value,ans[i+1].address);
    }
    printf("%05d %d -1\n",ans[i].address,ans[i].value);
}
