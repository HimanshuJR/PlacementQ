class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> count;
        vector<int> ans;
        for(auto it : nums){
            count[it]++;
        }
        for(auto it : count){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};