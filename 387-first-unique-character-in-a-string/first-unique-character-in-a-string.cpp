class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        
        // Count the frequency of each character in the string
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Find the first character with a count of 1
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1; // If no unique character is found
    }
};
