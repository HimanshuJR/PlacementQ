class Solution {
public:
void findcombination(vector<int>& candidates, int target,vector<vector<int>> &result, vector<int> &combination,int start){
    int n = candidates.size();

   // base case 
   if(target == 0){
    result.push_back(combination);
   }
   for(int i =start ;i<n;i++){
    if(candidates[i] <= target){
        combination.push_back(candidates[i]);
        findcombination(candidates,target-candidates[i],result,combination,i);
        combination.pop_back();
    }
   }

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // number of element in candidate array
       int n = candidates.size();
       vector<vector<int>> result;
        vector<int> combination;
        findcombination(candidates,target,result,combination,0);
        return result;
    }
    
};