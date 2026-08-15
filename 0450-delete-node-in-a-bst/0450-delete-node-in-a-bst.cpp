 class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        // Search for the key
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Node has no left child
            if (root->left == NULL)
                return root->right;

            // Node has no right child
            if (root->right == NULL)
                return root->left;

            // Node has both children
            TreeNode* successor = root->right;

            while (successor->left != NULL) {
                successor = successor->left;
            }

            root->val = successor->val;

            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};