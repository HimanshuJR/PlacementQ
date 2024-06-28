class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue <int,vector<int>, std::greater<int>> q;
        vector<int> ans;
        for(int x : nums){
            q.push(x);
        }
        
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }

        return ans;
    
        
    }
};