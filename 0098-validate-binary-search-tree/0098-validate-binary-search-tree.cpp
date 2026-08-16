 class Solution { 
    public:
    bool isValidBST(TreeNode* root ) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
        // Empty tree is a Valid BST
        if (root == NULL)
        return true;

        // Current noe must be ithin the allowed range
        if (root->val <= minVal || root->val >= maxVal)
        return false;

        // Left subtree: values must be smaller
        // Right subtree: values must be larger
        return isValidBST(root->left, minVal, root->val) && 
        isValidBST(root->right, root->val, maxVal);
    }
 };