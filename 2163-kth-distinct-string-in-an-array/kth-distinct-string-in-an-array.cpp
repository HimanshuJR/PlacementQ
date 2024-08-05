class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequency;

        // Count the frequency of each string
        for (const string& s : arr) {
            frequency[s]++;
        }

        // Collect distinct strings
        vector<string> distinctStrings;
        for (const string& s : arr) {
            if (frequency[s] == 1) {
                distinctStrings.push_back(s);
            }
        }

        // Check if k-th distinct string exists
        if (k <= distinctStrings.size()) {
            return distinctStrings[k - 1];
        }

        return ""; // Return an empty string if k-th distinct string does not exist
    }
};