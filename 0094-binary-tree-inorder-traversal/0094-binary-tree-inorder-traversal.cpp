 class Solution {
    public:
    void inorder(TreeNode* node, vector<int>& ans) {

        // Base case
        if(node == NULL)
        return;

        // Left
        inorder(node->left, ans);

        // Root
        ans.push_back(node-> val);

        // Right
        inorder(node->right, ans);
    }

    vector<int>
    inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder(root, ans);

        return ans;
    }
 };