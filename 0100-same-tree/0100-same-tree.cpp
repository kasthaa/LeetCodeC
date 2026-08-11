 class Solution {
    public:
    bool isSameTree(TreeNode* p, TreeNode* q){

        // Both are null
        if (p == NULL && q == NULL)
        return true;

        // One is Null , other is not 
        if(p == NULL || q == NULL )
        return false;

        // Values are different
        if(p -> val != q ->val)
        return false;

        // Check left ad right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
 };