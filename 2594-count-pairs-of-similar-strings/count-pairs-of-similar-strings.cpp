class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> freqMap; // To store the frequency of each bitmask
        int count = 0;
        
        for (const string& word : words) {
            int bitmask = 0;
            // Create a bitmask for the word
            for (char c : word) {
                bitmask |= (1 << (c - 'a')); // Set the bit corresponding to the character
            }
            
            // Count how many similar pairs we have encountered so far for this bitmask
            count += freqMap[bitmask];
            
            // Increment the frequency of this bitmask
            freqMap[bitmask]++;
        }
        
        return count;
    }
};
