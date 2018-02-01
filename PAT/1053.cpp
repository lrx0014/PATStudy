/// PAT 1053

#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

#define MAX 101

int weight[MAX];

map< int,vector<int> > adjlist;
int pre[MAX];
stack<int> path;

void print(int p)
{
	while(p!=-1)
	{
		path.push(p);
		p = pre[p];
	}
	printf("%d",weight[path.top()]);
	path.pop();
	while(!path.empty())
	{
		printf(" %d",weight[path.top()]);
		path.pop();
	}
	printf("\n");
}

void dfs(int p,const int s,int sum)
{
	sum += weight[p];
	if(sum>s)
	{
		return;
	}
	if(sum==s && adjlist[p].empty())
	{
		print(p);
		return;
	}
	if(adjlist[p].empty())
	{
		return;
	}
	for(vector<int>::reverse_iterator it = adjlist[p].rbegin();it!=adjlist[p].rend();it++)
	{
		dfs(*it,s,sum);
	}
}

void init(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		pre[i] = -1;
	}
}

bool cmp(int a,int b)
{
	return weight[a] < weight[b];
}

int main()
{
	int n,m,s;
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	init(n);
	int id,ln,sid;
	while(m--)
	{
		scanf("%d %d",&id,&ln);
		while(ln--)
		{
			scanf("%d",&sid);
			adjlist[id].push_back(sid);
			pre[sid] = id;
		}
		sort(adjlist[id].begin(),adjlist[id].end(),cmp);
	}
	dfs(0,s,0);
	return 0;
}
