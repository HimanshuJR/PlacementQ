class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> group_anagrams;
        for(const string& s: strs){
            string sortstrs = s;
            sort(sortstrs.begin(), sortstrs.end());
            group_anagrams[sortstrs].push_back(s);
        }
        vector<vector<string>> ans;
        for(const auto& pair : group_anagrams){
            ans.push_back(pair.second);
        }
        return ans;
    }
};