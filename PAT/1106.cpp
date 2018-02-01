/// PAT 1106  ?????

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int id;
	bool isRetailer;
	vector<Node> children;
};

Node rootNode;

int bfs(Node root,float price,float r)
{
	int level = 0;
	int count = 0;
	int cost = price;
	queue<Node> Q;
	Q.push(root);
	Node curNode;
	while(!Q.empty())
	{
		curNode = Q.front();
		Q.pop();
		if(curNode.isRetailer==true)
		{
			for(int i=0;i<level;i++)
			{
				cost *= r;
			}
			printf("%.4f %d",cost,curNode.children.size());
		}else{
			for(vector<Node>::iterator i=curNode.children.begin();i<curNode.children.end();i++)
			{
				Q.push(*i);
			}
			level++;
		}
	}
}

int main()
{
	int N;
	float P,R;
	cin>>N>>P>>R;
	Node node[1001];
	for(int i=0;i<N;i++)
	{
		int K;
		for(int j=0;j<K;j++)
		{
			int child_id;
			cin>>child_id;
			Node child;
			child.id = child_id;
			node[i].children.push_back(child);
		}
	}
}
