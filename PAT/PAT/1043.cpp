/// PAT 1043

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Node{
    Node *lchild;
    Node *rchild;
    int value;
}Tree[2000];

int loc;

Node *Create()
{
    Tree[loc].lchild = NULL;
    Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

Node *Insert1(Node *T,int x)
{
    if(T==NULL)
    {
        T = Create();
        T->value = x;
    }else{
        if(x < T->value)
        {
            T->lchild = Insert1(T->lchild,x);
        }else{
            T->rchild = Insert1(T->rchild,x);
        }
    }
    return T;
}

Node *Insert2(Node *T,int x)
{
    if(T==NULL)
    {
        T = Create();
        T->value = x;
    }else{
        if(x < T->value)
        {
            T->rchild = Insert2(T->rchild,x);
        }else{
            T->lchild = Insert2(T->lchild,x);
        }
    }
    return T;
}

void PreOrder(Node *T,vector<int> &v)
{
    v.push_back(T->value);
    if(T->lchild != NULL)
    {
        PreOrder(T->lchild,v);
    }
    if(T->rchild != NULL)
    {
        PreOrder(T->rchild,v);
    }
}

void PostOrder(Node *T,vector<int> &v)
{
    if(T->lchild != NULL)
    {
        PostOrder(T->lchild,v);
    }
    if(T->rchild != NULL)
    {
        PostOrder(T->rchild,v);
    }
    v.push_back(T->value);
}

int main()
{
    int n;
    vector<int> v1,v2,v3,v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }
    loc = 0;
    Node *T1 = NULL;
    Node *T2 = NULL;
    for(int i=0;i<n;i++)
    {
        T1 = Insert1(T1,v1[i]);
        T2 = Insert2(T2,v1[i]);
    }
    PreOrder(T1,v2);
    PreOrder(T2,v3);
    if(v2 != v1 && v3 != v1)
    {
        cout<<"NO\n";
        return 0;
    }else{
        cout<<"YES\n";
        if(v2==v1)
        {
            PostOrder(T1,v);
            for(int i=0;i<n-1;i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<v[n-1]<<"\n";
        }
        else if(v3==v1)
        {
            PostOrder(T2,v);
            for(int i=0;i<n-1;i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<v[n-1]<<"\n";
        }
    }
}
