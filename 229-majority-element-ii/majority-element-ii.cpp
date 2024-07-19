class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> count;
        unordered_map<int, bool> added;

        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (count[nums[i]] > n / 3 && !added[nums[i]]) {
                ans.push_back(nums[i]);
                added[nums[i]] = true;
            }
        }

        return ans;
    }
};