#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class TreeToSequence
{
  public:
    vector<int> pre, mid, post;
    vector<vector<int>> convert(TreeNode *root)
    {
        // write code here
        preorder(root);
        midorder(root);
        postorder(root);
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(mid);
        result.push_back(post);
        return result;
    }

    void preorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        pre.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    void midorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        midorder(root->left);
        mid.push_back(root->val);
        midorder(root->right);
    }

    void postorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        post.push_back(root->val);
    }
};