 class Solution{
    public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }

    int maxPathDown(TreeNode* node, int &maxi) {
        if (node== NULL)
        return 0;

        // Ignore nagative paths
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));

        // Path paassing though currten node
        maxi = max(maxi, left + right+ node->val);

        //Return maximun path going upward
        return node->val + max(left, right); 
    }
 };