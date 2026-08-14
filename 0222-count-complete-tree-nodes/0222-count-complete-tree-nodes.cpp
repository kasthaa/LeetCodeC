 class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        // Perfect binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        // Not perfect, recursively count
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int getLeftHeight(TreeNode* root) {
        int height = 0;

        while (root) {
            height++;
            root = root->left;
        }

        return height;
    }

    int getRightHeight(TreeNode* root) {
        int height = 0;

        while (root) {
            height++;
            root = root->right;
        }

        return height;
    }
};