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
void preorderHelper(TreeNode* root, vector<int>&arr){
     if(root == nullptr){
            return;
        }
    arr.push_back(root -> val);
    preorderHelper(root-> left,arr);
    preorderHelper(root-> right,arr);


}
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> arr;
       preorderHelper(root,arr);
       return arr;


    }
};