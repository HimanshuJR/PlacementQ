class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans;
        map<int,int> count;
        for(int i = 0;i<n;i++){
            count[nums[i]]++;
        }
        for(auto &[key,value] : count){
            if(value == 1){
               return key;
            }
        }
        return -1;
        
    }
};