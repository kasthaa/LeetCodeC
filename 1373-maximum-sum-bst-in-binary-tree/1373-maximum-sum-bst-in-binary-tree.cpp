 class Solution {
    struct Info {
        int minVal;
        int maxVal;
        int sum;
        bool isBST;

        Info(int mn, int mx, int s, bool bst)
            : minVal(mn), maxVal(mx), sum(s), isBST(bst) {}
    };

    int ans = 0;

    Info solve(TreeNode* root) {
        // Empty tree is a BST
        if (root == nullptr) {
            return Info(INT_MAX, INT_MIN, 0, true);
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        // Check if current subtree is a BST
        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return Info(
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                currSum,
                true
            );
        }

        // Not a BST
        return Info(INT_MIN, INT_MAX, 0, false);
    }

public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};