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

TreeNode* Helper(vector<int>& nums,int left,int right){
    // declaration of variables
    int n = nums.size();
    int mid = (left+right)/2;

    if( left > right){
        return nullptr;
    }
    // declare root
    TreeNode* node = new TreeNode(nums[mid]);
    node -> left =Helper(nums,left,mid-1);
    node -> right = Helper(nums,mid+1,right);
    return node; 
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
         return Helper(nums,0,n-1);
    }

};