 class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return solve(root, k, st);
    }

private:
    bool solve(TreeNode* root, int k, unordered_set<int>& st) {
        if (root == nullptr)
            return false;

        if (st.count(k - root->val))
            return true;

        st.insert(root->val);

        if (solve(root->left, k, st))
            return true;

        if (solve(root->right, k, st))
            return true;

        return false;
    }
};