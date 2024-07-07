class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = n+1;
        int start = 0 ;
        int sum = 0;
        
        for(int end = 0; end < n; end++){
            sum += nums[end];

            while(sum >= target){
                minLength = min(minLength , end - start+1);
                sum -= nums[start];
                start ++;
            }

        }
        return minLength == n+1 ? 0 : minLength;
    }
};