 class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, mp);
    }

private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& mp) {

        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        // First element of preorder is the root
        int rootValue = preorder[preStart];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int inRoot = mp[rootValue];

        // Number of nodes in left subtree
        int leftSize = inRoot - inStart;

        // Build left subtree
        root->left = build(
            preorder,
            preStart + 1,
            preStart + leftSize,
            inorder,
            inStart,
            inRoot - 1,
            mp
        );

        // Build right subtree
        root->right = build(
            preorder,
            preStart + leftSize + 1,
            preEnd,
            inorder,
            inRoot + 1,
            inEnd,
            mp
        );

        return root;
    }
};