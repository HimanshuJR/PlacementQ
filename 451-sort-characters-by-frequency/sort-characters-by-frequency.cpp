class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        
        // Count the frequency of each character
        for (auto c : s) {
            count[c]++;
        }
        
        // Create a vector of pairs {frequency, character}
        vector<pair<int, char>> freq;
        for (auto& it : count) {
            freq.push_back({it.second, it.first});
        }
        
        // Sort by frequency in descending order
        sort(freq.rbegin(), freq.rend());
        
        // Build the result string
        string ans = "";
        for (auto& it : freq) {
            ans += string(it.first, it.second);
        }
        
        return ans;
    }
};
