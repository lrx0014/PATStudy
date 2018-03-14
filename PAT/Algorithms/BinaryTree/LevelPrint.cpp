#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>

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

class TreePrinter
{
  public:
    vector<vector<int>> printTree(TreeNode *root)
    {
        // write code here
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> row;
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                row.push_back(cur->val);
                if (cur->left != NULL)
                {
                    q.push(cur->left);
                }
                if (cur->right != NULL)
                {
                    q.push(cur->right);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};