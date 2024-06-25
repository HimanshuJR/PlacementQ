class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int smallest_no = nums[0];
        for( int i = 0;i< n;i++){
            if(nums[i] < smallest_no){
                smallest_no = nums[i];
            }


        }
        return smallest_no;
    }
};