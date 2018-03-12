#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct node{
    int id;
    int childs_num;
    vector<int> childs;
}Node;

void dfs(const Node *tree,Node node,map<int,int>& m,int depth)
{
    if(m[depth==0]) m[depth] = 0;
    if(node.childs_num == 0)
    {
        ++m[depth];
        return;
    }
    vector<int> childs = node.childs;
    for(int i=0;i<childs.size();i++)
    {
        dfs(tree,tree[childs[i]],m,depth+1);
    }
}

int main()
{
    int N,M;
    cin>>N>>M;
    Node *tree = (Node*)malloc((N+1)*sizeof(Node));
    for(int i=0;i<100;i++)
    {
        tree[i].id = 0;
        tree[i].childs_num = 0;
    }
    int ID,K;
    while(M--)
    {
        cin>>ID>>K;
        tree[ID].id = ID;
        tree[ID].childs_num = K;
        int child;
        while(K--)
        {
            cin>>child;
            (*(tree+ID)).childs.push_back(child);
            //tree[ID].childs.push_back(child);
        }
    }
    map<int,int> result;
    dfs(tree,tree[1],result,1);
    bool first = 1;
    for(map<int,int>::iterator itor=result.begin();itor!=result.end();itor++)
    {
        if(first)
        {
            cout<<itor->second;
            first = 0;
        }
        else{
            cout<<" "<<itor->second;
        }
    }
}
