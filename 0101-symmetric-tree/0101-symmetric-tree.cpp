 class Solution{
    public:
    bool isSymmetric(TreeNode* root)
    {
        if (root== NULL)
        return true;

        return isMirror(root->left, root->right);
    }

    private:
    bool isMirror(TreeNode* left, TreeNode*right){
        // Both are NULL

        if (left ==NULL && right == NULL)
        return true;

        // One is NULL
        if(left == NULL || right == NULL)
        return false;

        // Values mus be equal
        if(left->val != right->val)
        return false;

        // Mirror check
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
 };