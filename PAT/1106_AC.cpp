/// PAT 1106 AC

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	int n;
	double price,rate;
	scanf("%d %lf %lf",&n,&price,&rate);
	vector<int> *arr = new vector<int>[n];
	int *arr_check = new int[n];
	for(int i=0;i<n;i++)
	{
		int size;
		scanf("%d",&size);
		arr_check[i] = size;
		arr[i] = vector<int>(size);
		for(int j=0;j<size;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int level = 0;
	int flag = 0;
	int count = 0;
	vector<int> vec;
	vec.push_back(0);
	if(arr[0].size()==0)
	{
		flag = 1;
		count++;
	}
	while(!flag)
	{
		vector<int> temp;
		for(int i=0;i<vec.size();i++)
		{
			for(int j=0;j<arr[vec[i]].size();j++)
			{
				if(arr_check[arr[vec[i]][j]]==0)
				{
					flag = 1;
					count++;
				}
				if(arr_check[arr[vec[i]][j]]!=0&&!flag)
				{
					temp.push_back(arr[vec[i]][j]);
				}
			}
			
		}
		level++;
		vec = vector<int>(temp);
	}
	printf("%.4f %d\n",price*pow(rate/100.0+1,level*1.0),count);
}
