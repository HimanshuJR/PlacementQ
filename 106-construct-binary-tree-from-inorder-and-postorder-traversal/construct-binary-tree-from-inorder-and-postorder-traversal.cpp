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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, unordered_map<int, int>& map, int poststart, int postEnd, int instart, int inEnd) {
        // All nodes are traversed
        if (poststart > postEnd || instart > inEnd) return nullptr;

        // The root is the last element in the current postorder segment
        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);

        // Find the index of the root in inorder traversal
        int inrootindex = map[rootValue];

        // Calculate the number of elements in the left subtree
        int leftTreeSize = inrootindex - instart;

        // Recursively build the left subtree
        root->left = helper(postorder, inorder, map, poststart, poststart + leftTreeSize - 1, instart, inrootindex - 1);

        // Recursively build the right subtree
        root->right = helper(postorder, inorder, map, poststart + leftTreeSize, postEnd - 1, inrootindex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        // Build a map to store the indices of elements in inorder traversal
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        // Call the helper function to construct the tree
        return helper(postorder, inorder, map, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};
