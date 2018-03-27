
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class MaxSubtree {
public:
    TreeNode* getMax(TreeNode* root) {
        // write code here
        if(root == NULL)
        {
            return NULL;
        }
        int max,min,num;
        return postorder(root,max,min,num);
    }

    TreeNode* postorder(TreeNode* root,int& maxNode,int& minNode,int& num)
    {
        if(root == NULL)
        {
            minNode = INT_MAX;
            maxNode = INT_MIN;
            num = 0;
            return NULL;
        }

        int lmax,lmin,lnum;
        TreeNode* lnode = postorder(root->left,lmax,lmin,lnum);

        int rmax,rmin,rnum;
        TreeNode* rnode = postorder(root->right,rmax,rmin,rnum);

        maxNode = max(rmax,root->val);
        minNode = min(lmin,root->val);

        if(lmax<root->val && rmin>root->val && root->left==lnode && root->right==rnode)
        {
            num = lnum + rnum + 1;
            return root;
        }
        if(lnum>rnum)
        {
            num = lnum;
            return lnode;
        }else{
            num = rnum;
            return rnode;
        }
    }
};
