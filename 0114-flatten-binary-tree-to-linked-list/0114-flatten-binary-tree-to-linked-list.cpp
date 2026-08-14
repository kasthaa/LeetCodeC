 class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;

        while (cur != NULL) {

            if (cur->left != NULL) {

                // Find the rightmost node of left subtree
                TreeNode* prev = cur->left;

                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // Connect right subtree after the predecessor
                prev->right = cur->right;

                // Move left subtree to the right
                cur->right = cur->left;
                cur->left = NULL;
            }

            // Move to the next node
            cur = cur->right;
        }
    }
};