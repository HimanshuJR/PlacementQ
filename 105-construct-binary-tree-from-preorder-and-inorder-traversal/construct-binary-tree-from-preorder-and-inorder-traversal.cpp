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
TreeNode* helper(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& map, int prestart, int preEnd,int instart,int inEnd){
        // all nodes are traversed 
        if(prestart > preEnd || instart > inEnd) return nullptr;

        int rootValue = preorder[prestart];
        TreeNode* root = new TreeNode(rootValue);

        int inrootindex = map[rootValue];

        int leftTreeSize = inrootindex - instart;


        root -> left = helper( preorder, inorder,  map, prestart+1,  prestart+ leftTreeSize, instart,inrootindex-1);
        root -> right =helper(preorder,  inorder,  map,  prestart + leftTreeSize+1,preEnd,inrootindex+1, inEnd); 
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> map;
        for(int i = 0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
       return helper(preorder, inorder, map, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};