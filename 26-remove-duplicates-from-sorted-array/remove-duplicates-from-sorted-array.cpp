class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;  
        }
        
        int newSize = 1;  
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[newSize] = nums[i];  
                newSize++;
            }
        }
        
        return newSize;
    }
};