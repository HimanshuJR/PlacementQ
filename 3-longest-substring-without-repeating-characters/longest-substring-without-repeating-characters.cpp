class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;  // Store the last index of each character
        int maxlength = 0;                    // Maximum length of substring found
        int start = 0;                        // Start index of current substring

        for (int i = 0; i < s.size(); i++) {
            // Check if the character is already in the map
            if (charIndex.find(s[i]) != charIndex.end()) {
                // Update start index to the right of the last occurrence
                start = max(start, charIndex[s[i]] + 1);
            }
            charIndex[s[i]] = i;  // Update the last index of the character
            maxlength = max(maxlength, i - start + 1);  // Update maximum length
        }
        return maxlength;  // Return the maximum length found
    }
};
