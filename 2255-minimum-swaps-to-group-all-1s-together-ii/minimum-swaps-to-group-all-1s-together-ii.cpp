#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Count total number of 1s in the array
        int totalOnes = count(nums.begin(), nums.end(), 1);
        
        // If there are no 1s, return 0
        if (totalOnes == 0) {
            return 0;
        }
        
        // Create an extended array to handle the circular nature
        vector<int> extended(nums.begin(), nums.end());
        extended.insert(extended.end(), nums.begin(), nums.end());
        
        // Initialize the maximum number of 1s in any window of size `totalOnes`
        int maxOnesInWindow = 0;
        int currentOnes = 0;
        
        // Count the number of 1s in the first window of size `totalOnes`
        for (int i = 0; i < totalOnes; ++i) {
            if (extended[i] == 1) {
                currentOnes++;
            }
        }
        maxOnesInWindow = currentOnes;
        
        // Use a sliding window to count the number of 1s in other windows of size `totalOnes`
        for (int i = totalOnes; i < 2 * n; ++i) {
            if (extended[i] == 1) {
                currentOnes++;
            }
            if (extended[i - totalOnes] == 1) {
                currentOnes--;
            }
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }
        
        // Minimum swaps required will be the total number of 1s minus the maximum number of 1s in any window of size `totalOnes`
        return totalOnes - maxOnesInWindow;
    }
};
