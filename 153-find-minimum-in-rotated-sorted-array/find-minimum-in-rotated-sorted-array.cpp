class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        
        while(start < end){
            int mid = (start+end)/2;

            if(nums[mid] > nums[end]){
                // move to the right part 
                start = mid+1;
            }
            else {
                end = mid;
            }


        }
        return nums[start];

    }
};