class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = n+1;
        int sum = 0;
        int start = 0;
        

        for( int i  = 0 ;i < n; i++){
            sum += nums[i];
        
        while( sum >= target){
            minLength = min(minLength, i-start+1);
            sum -= nums[start];
            start++;
        }
    }
        return minLength == n+1 ? 0 : minLength;
    }
        
};