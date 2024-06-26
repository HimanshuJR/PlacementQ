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
    void InTraversal(TreeNode* root, vector<int>& inorder){
        if(!root) return;
        // Left Node Right
        InTraversal(root-> left,inorder);
        inorder.push_back(root-> val);
        InTraversal( root -> right, inorder);
        
    }
    TreeNode* ConstructaBST(vector<int>& in,int low, int high){
        if( low > high) return nullptr;
        int mid = (low+high)/2;
        TreeNode* curr = new TreeNode(in[mid]);
        curr -> left = ConstructaBST(in,low, mid-1);
        curr -> right = ConstructaBST(in,mid+1,high);
        return curr;

    }

    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> inorder;
        InTraversal(root,inorder);
        return ConstructaBST(inorder,0,inorder.size()-1);

    }
};