class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        // Convert intervals to pairs for sorting and easier access
        vector<pair<int, int>> p;
        for (int i = 0; i < intervals.size(); i++) {
            p.push_back({intervals[i][0], intervals[i][1]});
        }

        // Sort the pairs by the first element of each pair
        sort(p.begin(), p.end());

        // Initialize the first interval
        vector<vector<int>> ans;
        int first = p[0].first;
        int second = p[0].second;

        // Traverse through the pairs and merge intervals
        for (int i = 1; i < p.size(); i++) {
            if (second >= p[i].first) {
                // Merge intervals
                second = max(second, p[i].second);
            } else {
                // Add the merged interval to the answer
                ans.push_back({first, second});
                // Update the first and second for the new interval
                first = p[i].first;
                second = p[i].second;
            }
        }

        // Add the last interval
        ans.push_back({first, second});
        return ans;
    }
};