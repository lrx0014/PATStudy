/// PAT 1020

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int l,r,il,ir;
    Node(){}
    Node(int ll,int rr,int ill,int irr):l(ll),r(rr),il(ill),ir(irr){}
};

queue<Node> q;

int post[100],in[100];

int Find(int x,int l,int r)
{
    for(int i=l;i<=r;i++)
    {
        if(in[i]==x)
        {
            return i;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }

    bool first = true;
    q.push(Node(0,n-1,0,n-1));
    while(!q.empty())
    {
        Node t = q.front();
        if(first)
        {
            printf("%d",post[t.r]);
            first = false;
        }else{
            printf(" %d",post[t.r]);
        }
        q.pop();
        if(t.l<t.r)
        {
            int im = Find(post[t.r],t.il,t.ir);
            if(t.il<im)
            {
                q.push(Node(t.l,t.l+im-t.il-1,t.il,im-1));
            }
            if(im<t.ir)
            {
                q.push(Node(t.l+im-t.il,t.r-1,im+1,t.ir));
            }
        }
    }
    return 0;
}
