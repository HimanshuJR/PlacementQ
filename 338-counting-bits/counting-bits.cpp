class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> res(n + 1);  // Create a vector to store the results
        int offset = 1;  // Initialize offset to the smallest power of 2 (1)

        for (int i = 1; i <= n; i++) {
            if (i == offset * 2) {  // When i reaches the next power of 2, update offset
                offset = i;
            }
            res[i] = res[i - offset] + 1;  // Calculate res[i] using the offset
        }

        return res;
    }
};