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


class TreeToString {
public:
    string str;
    string toString(TreeNode* root) {
        // write code here
        preorder(root);
        return str;
    }
    
    void preorder(TreeNode* root)
    {
        if(root == NULL)
        {
            str += "#!";
            return;
        }
        str += to_string(root->val) + "!";
        preorder(root->left);
        preorder(root->right);
    }
};