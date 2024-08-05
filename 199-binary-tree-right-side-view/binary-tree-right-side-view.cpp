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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if( root == nullptr){
            return ans;
        }
        // we will use bfs to solve this problem 
        queue<TreeNode*> q;
        q.push(root);

        while( !q.empty()){
           int level_size = q.size();
           int rightmost = 0;

           for( int i = 0;i< level_size;i++){
            TreeNode* node = q.front();
            q.pop();
             

            if( i == level_size-1){
                 rightmost = node -> val;
            }
            if( node -> left){
                q.push(node -> left);
            }
            if( node -> right){
                q.push(node -> right);
            }
           }
           ans.push_back(rightmost);
        }
        return ans;


    }
};