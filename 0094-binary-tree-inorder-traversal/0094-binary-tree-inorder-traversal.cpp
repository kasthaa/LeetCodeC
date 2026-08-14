 class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;

        while (cur != NULL) {

            // If there is no left subtree
            if (cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }

            else {
                // Find the inorder predecessor
                TreeNode* prev = cur->left;

                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }

                // Create a thread
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                }

                // Remove the thread
                else {
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return inorder;
    }
};