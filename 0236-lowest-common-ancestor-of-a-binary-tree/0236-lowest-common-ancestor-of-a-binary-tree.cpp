class Solution {
    public:
    TreeNode*
    lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case
        if (root == NULL || root == p || root == q)
        return root;

        //Search in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search i right subTree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Both sides found p and q
        if(left != NULL && right != NULL)
        return root;

        // Return whichever side found a node
        if(left != NULL )
        return left;   

        return right; 
    }
};