class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Call the function to find the minimum number of pages
        return findPages(nums, nums.size(), k);
    }

private:
    bool canAllocate(const vector<int>& arr, int n, int m, int maxPages) {
        int studentCount = 1;
        int currentPageSum = 0;

        for(int i = 0; i < n; i++) {
            if(currentPageSum + arr[i] > maxPages) {
                studentCount++;
                currentPageSum = arr[i];
                if(studentCount > m) {
                    return false;
                }
            } else {
                currentPageSum += arr[i];
            }
        }
        return true;
    }

    int findPages(const vector<int>& arr, int n, int m) {
        if(m > n) {
            return -1;  // Impossible to allocate
        }

        int maxPages = *max_element(arr.begin(), arr.end());
        int totalPages = accumulate(arr.begin(), arr.end(), 0);

        int low = maxPages;
        int high = totalPages;
        int result = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canAllocate(arr, n, m, mid)) {
                result = mid;  // Try for a better minimum
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};