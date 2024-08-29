class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int current_length = 1;
        int max_length = 1;
        if(n== 0) return 0;

        sort(nums.begin() , nums.end());
        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if( nums[i] - nums[i-1] == 1){
                current_length++;
            }else{
                current_length = 1;
            }
            max_length = max(max_length, current_length);
            
        }
        return max_length;
    }
};