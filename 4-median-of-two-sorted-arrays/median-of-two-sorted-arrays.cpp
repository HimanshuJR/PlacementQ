class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p = nums1.size();
        int m = nums2.size();
        
        // Ensure nums1 is the smaller array
        if (p > m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        // Binary search variables
        int low = 0, high = p;
        int halfLen = (p + m + 1) / 2; // Total number of elements in the left half
        
        while (low <= high) {
            int i = (low + high) / 2;
            int j = halfLen - i;
            
            // Determine the partition position
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == p) ? INT_MAX : nums1[i];
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == m) ? INT_MAX : nums2[j];
            
            // Check if partition is correct
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Calculate median
                if ((p + m) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = i - 1; // Move partition left in nums1
            } else {
                low = i + 1; // Move partition right in nums1
            }
        }
         throw invalid_argument("Input arrays are not sorted or are invalid");
    
    }
};
