class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                         if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1; k < n - 1; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    for (int m = k + 1; m < n; m++) {  
                         if (m > k + 1 && nums[m] == nums[m - 1]) continue;
                        if ((long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[m] == target) {
                            ans.push_back({nums[i], nums[j], nums[k], nums[m]});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
