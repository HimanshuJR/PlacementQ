class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1); // Initialize the output array

        // Calculate left products
        int left = 1;
        for (int i = 0; i < n; i++) {
            output[i] = left; // Set the left product for the current index
            left *= nums[i];   // Update the left product
        }

        // Calculate right products and update the output
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= right; // Multiply with the right product
            right *= nums[i];    // Update the right product
        }

        return output; // Return the final output array
    }
};
