class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        int sum;
        
        for( int i = 0; i< p;i++){
            ans.push_back(nums1[i]);
        }
        for( int j = 0; j< m;j++){
            ans.push_back(nums2[j]);
        }
        sort(ans.begin(), ans.end());
       int n = ans.size();
        if (n % 2 != 0) {
        // If n is odd, return the middle element
        return ans[n / 2];
    } else {
        // If n is even, return the average of the two middle elements
        return (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
    }

    }
};