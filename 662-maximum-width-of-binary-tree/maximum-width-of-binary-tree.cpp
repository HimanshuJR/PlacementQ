class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int level_size = q.size();
            unsigned long long leftmost = q.front().second;
            unsigned long long rightmost = q.back().second;
            maxWidth = max(maxWidth, static_cast<int>(rightmost - leftmost + 1));

            for (int i = 0; i < level_size; ++i) {
                auto [node, index] = q.front();
                q.pop();

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }
        }

        return maxWidth;
    }
};
