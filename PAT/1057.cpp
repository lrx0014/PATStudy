/// PAT 1057 ·ÖÖÎ·¨ 

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

const int _size = 100000;
const int capi = 500;
int bucket[_size/capi][capi];
int count[_size/capi];
int getmid(int size)
{
	int ind = (size+1)/2,cnt = 0,i,j;
	for(i=0;i<_size/capi;i++)
	{
		if(cnt + count[i]>=ind)
		{
			break;
		}
		cnt += count[i];
	}
	for(j=0;j<capi;j++)
	{
		cnt += bucket[i][j];
		if(cnt>=ind)
		{
			return j + i * capi;
		}
	}
}

char cmd[10];
int main()
{
	int n,tmp;
	scanf("%d",&n);
	stack<int> s;
	while(n--)
	{
		scanf("%s",cmd);
		switch(cmd[1])
		{
			case 'e':
				if(s.empty()) printf("Invalid\n");
				else printf("%d\n",getmid(s.size())+1);
			break;
			
			case 'o':
				if(s.empty())
				{
					cout<<"Invalid\n";
				}else{
					tmp = s.top();
					s.pop();
					cout<<tmp<<"\n";
					tmp--;
					bucket[tmp/capi][tmp%capi]--;
					count[tmp/capi]--;
				}
				break;
				
				case 'u':
					cin>>tmp;
					s.push(tmp);
					tmp--;
					bucket[tmp/capi][tmp%capi]++;
					count[tmp/capi]++;
					break;
		}
	}
}
