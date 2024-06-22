class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        
        // Sort both vectors
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int child = 0; 
        int cookie = 0;

        while (child < n && cookie < m) {
            if (s[cookie] >= g[child]) {
                child++;
            }
            cookie++;
        }
        return child;
    }
};