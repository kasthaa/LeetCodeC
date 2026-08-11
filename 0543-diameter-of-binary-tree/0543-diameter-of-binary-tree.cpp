 class Solution {
    public:
    int diameterOfBinaryTree(TreeNode* root){
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    private:
    int height(TreeNode* node, int& diameter){
        if (node ==NULL)
        return 0;
        
        int lh = height(node->left,diameter);
        int rh = height(node->right, diameter);

        // Diameter passing through this node
        diameter = max(diameter, lh+rh);

        // Return height of thus node
        return 1 + max(lh, rh);
    }
 };