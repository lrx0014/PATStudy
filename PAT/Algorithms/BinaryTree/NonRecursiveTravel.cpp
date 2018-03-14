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
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *temp = new TreeNode(0);
        while (!s.empty())
        {
            temp = s.top();
            pre.push_back(temp->val);
            s.pop();
            if (temp->right != NULL)
            {
                s.push(temp->right);
            }
            if (temp->left != NULL)
            {
                s.push(temp->left);
            }
        }
    }

    void midorder(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (!s.empty() || cur != NULL)
        {
            if (cur != NULL)
            {
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = s.top();
                s.pop();
                mid.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

    void postorder(TreeNode *root)
    {
        stack<TreeNode *> s1, s2;
        TreeNode *cur = NULL;
        s1.push(root);
        while (!s1.empty())
        {
            cur = s1.top();
            s1.pop();
            s2.push(cur);
            if (cur->left != NULL)
            {
                s1.push(cur->left);
            }
            if (cur->right != NULL)
            {
                s1.push(cur->right);
            }
        }
        while (!s2.empty())
        {
            cur = s2.top();
            post.push_back(cur->val);
            s2.pop();
        }
    }
};