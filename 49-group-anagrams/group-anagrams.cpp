class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map_anagrams;
        for( const string& s : strs){
           string sortedstrs = s;
           sort(sortedstrs.begin(), sortedstrs.end());
           map_anagrams[sortedstrs].push_back(s);
        }
        vector<vector<string>> ans;
        for(const auto& pair : map_anagrams){
            ans.push_back(pair.second);
        }
        return ans;
 
    }
};