class Solution {
public:
 void subset(int start ,vector<int> &ans,vector<int>& nums,vector<vector<int> > &finalans,int n){
    finalans.push_back(ans);
    for(int i = start ;i<n;i++){
        if( i > start && nums[i] == nums[i-1]){
            continue;
        }
        ans.push_back(nums[i]);
        subset(i+1,ans,nums,finalans,n);
        ans.pop_back();
    }

 }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> finalans ;
        vector<int> ans;
        sort(nums.begin() , nums.end());

        subset(0,ans,nums,finalans,n);
        return finalans;
    }
        
};