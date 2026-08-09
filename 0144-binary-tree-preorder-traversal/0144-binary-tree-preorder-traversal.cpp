 class Solution {
public:

    void preorder(TreeNode* node, vector<int>& ans) {
        if (node == NULL)
            return;

        // Root
        ans.push_back(node->val);

        // Left
        preorder(node->left, ans);

        // Right
        preorder(node->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preorder(root, ans);

        return ans;
    }
};