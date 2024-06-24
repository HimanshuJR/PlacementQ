class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate the midpoint

            if (nums[mid] == target) {
                return mid; // Target found
            }

            // Determine which part is sorted
            if (nums[start] <= nums[mid]) {
                // Left part is sorted
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1; // Target is in the left part
                } else {
                    start = mid + 1; // Target is in the right part
                }
            } else {
                // Right part is sorted
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1; // Target is in the right part
                } else {
                    end = mid - 1; // Target is in the left part
                }
            }
        }

        return -1; // Target not found
    }
};
