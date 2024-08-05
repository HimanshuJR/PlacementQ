class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int level_size = q.size();
            vector<TreeNode*> nodes_at_level;

            // Collect all nodes at the current level
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodes_at_level.push_back(node);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            // Reverse nodes at the current level if the level is odd
            if (level % 2 == 1) {
                int n = nodes_at_level.size();
                for (int i = 0; i < n / 2; ++i) {
        swap(nodes_at_level[i]->val, nodes_at_level[n - 1 - i]->val);
                }
            }

            level++;
        }

        return root;
    }
};