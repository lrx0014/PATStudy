/// PAT 1135

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node{
    int data;
    Node *lchild,*rchild;
};

Node *root;

void Insert(Node* &T,int data)
{
    if(T==NULL)
    {
        T = new Node();
        T->data = data;
        T->lchild = T->rchild = NULL;
        return;
    }

    if(abs(data) < abs(T->data))
    {
        Insert(T->lchild,data);
    }else{
        Insert(T->rchild,data);
    }
}

bool flag;

void judge1(Node *T)
{
    if(flag==false)
    {
        return;
    }

    if(T->lchild != NULL)
    {
        if(T->data<0 && T->lchild->data<0)
        {
            flag = false;
            return;
        }else{
            judge1(T->lchild);
        }
    }

    if(T->rchild != NULL)
    {
        if(T->data<0 && T->rchild->data<0)
        {
            flag = false;
            return;
        }else{
            judge1(T->rchild);
        }
    }
}

int judge2(Node *T)
{
    int l1,l2;
    if(flag==false)
    {
        return -1;
    }

    if(T==NULL)
    {
        return 1;
    }

    l1 = judge2(T->lchild);
    l2 = judge2(T->rchild);

    if(l1 != l2)
    {
        flag = false;
        return -1;
    }else{
        l1 = l1 + (T->data>0);
    }

    return l1;
}

int main()
{
    int k,n,data;
    scanf("%d",&k);
    while(k--)
    {
        flag = true;
        root = NULL;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&data);
            Insert(root,data);
        }
        if(root->data<0)
        {
            printf("No\n");
        }else{
            judge1(root);
            if(flag==false)
            {
                printf("No\n");
            }else{
                judge2(root);
                if(flag==false)
                {
                    printf("No\n");
                }else{
                    printf("Yes\n");
                }
            }
        }
    }
}
