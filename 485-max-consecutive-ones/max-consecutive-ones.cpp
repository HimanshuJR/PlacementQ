class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxlength = 0;
        for(auto it: nums){
            if(it == 1){
                count++;
                maxlength = max(maxlength, count);
            }else{
                count = 0;
            }
        }
        return maxlength;
    }
};