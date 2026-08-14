class Solution {
public:
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int distance = 0;

        while (!q.empty()) {
            int size = q.size();

            if (distance == k)
                break;

            distance++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Left child
                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                // Right child
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                // Parent
                if (parent[node] && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};