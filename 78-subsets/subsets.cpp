class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalans;
        int n = nums.size();
        
        // Start with an empty subset
        finalans.push_back({});
        
        // Iterate through each element in nums
        for (int i = 0; i < n; i++) {
            int currSize = finalans.size();
            for (int j = 0; j < currSize; j++) {
                // Create a new subset by adding the current element to an existing subset
                vector<int> newSubset = finalans[j];
                newSubset.push_back(nums[i]);
                finalans.push_back(newSubset);
            }
        }
        
        return finalans;
    }
};
