 class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // column -> row -> values
        map<int, map<int, multiset<int>>> nodes;

        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            nodes[col][row].insert(node->val);

            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }

        vector<vector<int>> ans;

        for (auto &col : nodes) {
            vector<int> temp;

            for (auto &row : col.second) {
                for (int value : row.second) {
                    temp.push_back(value);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};