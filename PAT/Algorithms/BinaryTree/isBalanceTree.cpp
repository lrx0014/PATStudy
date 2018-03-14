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

class CheckBalance {
public:
    bool check(TreeNode* root) {
        // write code here
        bool res = true;
        getHeight(root,1,res);
        return res;
    }
    
    int getHeight(TreeNode* root,int level,bool& res)
    {
        if(root == NULL)
        {
            return level;
        }
        int LH = getHeight(root->left,level+1,res);
        if(!res)
        {
            return level;
        }
        int RH = getHeight(root->right,level+1,res);
        if(!res)
        {
            return level;
        }
        if(abs(LH-RH)>1)
        {
            res = false;
        }
        return max(LH,RH);
    }
};