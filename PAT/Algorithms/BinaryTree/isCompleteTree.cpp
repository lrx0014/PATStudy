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


class CheckCompletion {
public:
    bool chk(TreeNode* root) {
        // write code here
        queue<TreeNode*> q;
        TreeNode* cur = root;
        while(cur != NULL)
        {
            q.push(cur->left);
            q.push(cur->right);
            cur = q.front();
            q.pop();
        }
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            if(cur != NULL)
            {
                return false;
            }
        }
        return true;
    }
};