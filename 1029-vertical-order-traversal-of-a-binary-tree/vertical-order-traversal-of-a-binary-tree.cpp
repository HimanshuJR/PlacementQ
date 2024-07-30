class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        // Map to store nodes at each horizontal distance (line) and level
        map<int, map<int, multiset<int>>> nodes;
        // Queue to store the node along with its horizontal distance and level
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        // Start with the root at horizontal distance 0 and level 0
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second.first;
            int level = it.second.second;

            // Store the node's value in the map
            nodes[line][level].insert(node->val);

            // If left child exists, push it to the queue with updated line and level
            if (node->left != nullptr) {
                q.push({node->left, {line - 1, level + 1}});
            }
            // If right child exists, push it to the queue with updated line and level
            if (node->right != nullptr) {
                q.push({node->right, {line + 1, level + 1}});
            }
        }

        // Traverse the map and collect the nodes in vertical order
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};