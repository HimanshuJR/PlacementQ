/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int height(TreeNode* Node) {
        if (Node == NULL) {
            return 0;
        }

        int left = height(Node->left);
        int right = height(Node->right);
        int ans = max(left, right) + 1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if (root == NULL) {
            return 0;
        }

        int leftSubtree = diameterOfBinaryTree(root->left);
        int rightSubtree = diameterOfBinaryTree(root->right);
        int combo = height(root->left) + height(root->right);
        
        int ans1 = max(leftSubtree, max(rightSubtree, combo));
        return ans1;
    }
};