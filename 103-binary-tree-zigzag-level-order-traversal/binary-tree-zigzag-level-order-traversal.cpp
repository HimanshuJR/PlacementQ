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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        while(!q.empty()){

        int level_size = q.size();
        vector<int> level_nodes(level_size);

        for(int i = 0;i< level_size;i++){
            TreeNode* node = q.front();
            q.pop();
            int index = left_to_right ? i : (level_size - 1 - i);
                level_nodes[index] = node->val;
            if( node -> left){
                q.push(node -> left);
            }
             if( node -> right){
                q.push(node -> right);
            }
          
        }
          ans.push_back(level_nodes);
          left_to_right = !left_to_right;

        }
        return ans;


    }
};