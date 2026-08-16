 class Solution{
    public:
    TreeNode*
    lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == NULL)
        return NULL;

        // Both p and q are in the right subtree
        if(root->val < p->val && root->val < q->val) {
            return
            lowestCommonAncestor(root->right, p, q);
        }

        // Both p and q are in the left subtree
        if(root->val > p->val && root->val > q->val) {
            return
            lowestCommonAncestor(root->left, p, q);
        }

        // One is on left and one is on right
        // OR root itself is p or q
        return root;
    }
 };