 class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* cur = root;
        TreeNode* prev = nullptr;

        while (cur != nullptr || !st.empty()) {

            // Go as left as possible
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* temp = st.top();

                // If right child exists and is not processed
                if (temp->right != nullptr && temp->right != prev) {
                    cur = temp->right;
                }
                else {
                    // Process the node
                    ans.push_back(temp->val);
                    prev = temp;
                    st.pop();
                }
            }
        }

        return ans;
    }
};