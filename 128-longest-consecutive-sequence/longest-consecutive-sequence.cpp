class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 

        // Sort the vector
        sort(nums.begin(), nums.end());

        int currentStreak = 1;
        int longestStreak = 1;

        for (int i = 1; i < n; i++) {
            // Skip duplicates
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    currentStreak++;
                } else {
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        return max(longestStreak, currentStreak);
    }
};
