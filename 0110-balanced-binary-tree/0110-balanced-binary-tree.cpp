 class Solution {
public:

    int dfsHeight(TreeNode* root) {
        // Base case
        if (root == NULL)
            return 0;

        // Height of left subtree
        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1)
            return -1;

        // Height of right subtree
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1)
            return -1;

        // Check balance condition
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height of current tree
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};