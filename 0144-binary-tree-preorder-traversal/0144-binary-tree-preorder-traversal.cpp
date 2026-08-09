 class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;

        if (root == NULL)
            return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            preorder.push_back(node->val);

            // Right first because stack is LIFO
            if (node->right != NULL)
                st.push(node->right);

            // Left second so that left is processed first
            if (node->left != NULL)
                st.push(node->left);
        }

        return preorder;
    }
};