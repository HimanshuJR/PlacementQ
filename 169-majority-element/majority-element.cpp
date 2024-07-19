class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // lets do it using maps 
        unordered_map<int,int> count;
        int maxfreq = 0;
        int maxans = 0;

        for(int i = 0; i<n ;i++){
            count[nums[i]]++;
            maxfreq = max(maxfreq, count[nums[i]]);
        }
        for(int i = 0;i<n;i++){
            if(maxfreq == count[nums[i]]){
                maxans = nums[i];
                break;
            }
        }
        return maxans;


    }
};