// we can two pointer approach here 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int left  =0;
        int right = n-1;
        int index = n-1;
        while( left <= right){
            int leftsquare  = nums[left]*nums[left];
            int rightsquare = nums[right]*nums[right];
            if(leftsquare > rightsquare){
                ans[index--] = leftsquare;
                left ++;

            }
            else{
                ans[index--] = rightsquare;
                right--;
            }

        }
        return ans;
    }
};