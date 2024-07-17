class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int ways = 0;
        for( int i = 0 ; i < n;i++){
            // if the sum is equal to target k
            int sum = 0;
            for(int j = i;j<n;j++){ 
            sum += nums[j];
            
            if(sum == k){
                ways++;
            }
        }
    }
        return ways;
    }
};