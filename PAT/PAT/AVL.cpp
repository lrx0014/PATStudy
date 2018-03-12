//PAT 1123

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

#define MAXN 30

typedef struct Node* AVLTree;
struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k):key(k),left(NULL),right(NULL),height(0){}
    Node(){}
};

int n;

int height(Node* node)
{
    if(node)
    {
        return node->height;
    }else{
        return -1;
    }
}

Node* LL(Node* k2)
{
    Node* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left),height(k2->right)) + 1;
    k1->height = max(height(k2->left),k2->height) + 1;

    return k1;
}

Node* RR(Node* k2)
{
    Node* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->height = max(height(k2->left),height(k2->right)) + 1;
    k1->height = max(height(k1->right),k2->height) + 1;

    return k1;
}

Node* LR(Node* k3)
{
    k3->left = RR(k3->left);
    return LL(k3);
}

Node* RL(Node* k3)
{
    k3->right = LL(k3->right);
    return RR(k3);
}

Node* Insert(AVLTree root,int key)
{
    if(!root)
    {
        root = new Node(key);
    }else if(root->key < key)
    {
        root->right = Insert(root->right,key);
        if(height(root->right)-height(root->left) == 2)
        {
            if(key > root->right->key)
            {
                root = RR(root);
            }else{
                root = RL(root);
            }
        }


    }else if(root->key > key)
    {
        root->left = Insert(root->left,key);
        if(height(root->left) - height(root->right) == 2)
        {
            if(key < root->left->key)
            {
                root = LL(root);
            }else{
                root = LR(root);
            }
        }
    }

    root->height = 1 + max(height(root->left),height(root->right));
    return root;
}

void Travel(AVLTree root)
{
    queue<Node*> Q;
    vector<int> level;
    Q.push(root);

    while(!Q.empty())
    {
        root = Q.front();
        Q.pop();
        level.push_back(root->key);
        if(root->left)
        {
            Q.push(root->left);
        }
        if(root->right)
        {
            Q.push(root->right);
        }
    }

    for(int i=0;i<level.size();++i)
    {
        if(i)
        {
            cout<<" ";
        }
        cout<<level[i];
    }
}

bool isComplete(AVLTree root)
{
    queue<Node*> Q;
    Q.push(root);
    bool haveNULL = false;

    while(!Q.empty())
    {
        root = Q.front();
        Q.pop();
        if(haveNULL)
        {
            if(root->left || root->right)
            {
                return false;
            }
        }
        if(root->left && root->right)
        {
            Q.push(root->left);
            Q.push(root->right);
        }else if(root->left && !root->right)
        {
            Q.push(root->left);
            haveNULL = true;
        }else if(!root->left && root->right)
        {
            return false;
        }else{
            haveNULL = true;
        }
    }
    return true;
}


int main()
{
    cin>>n;
    int key;
    AVLTree root = NULL;
    for(int i=0; i<n; ++i)
    {
        cin>>key;
        root = Insert(root,key);
    }
    Travel(root);
    cout<<"\n";
    if(isComplete(root))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
