 class Solution{
    public:
    void postorder(TreeNode* node, vector<int>& ans){
        if (node == NULL)
        return;

        // Left
        postorder(node -> left, ans);

        // Right
        postorder(node -> right, ans);

        // Root
        ans.push_back(node->val);
    }

    vector<int>
    postorderTraversal(TreeNode* root) {
        vector<int> ans;

        postorder(root, ans);

        return ans;
    }
 };