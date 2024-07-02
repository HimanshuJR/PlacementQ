class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> a;
        vector<int> c;
        if(intervals.size()<2)
            return intervals;
        sort(intervals.begin(), intervals.end());
        pair <int,int> b;
        b.first = intervals[0][0];
        b.second = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(b.second>=intervals[i][0])
                b.second=max(b.second,intervals[i][1]);
            else{
                c.push_back(b.first);
                c.push_back(b.second);
                a.push_back(c);
                c.clear();
                b.first=intervals[i][0];
                b.second=intervals[i][1];
            }
        }
        c.push_back(b.first);
        c.push_back(b.second);
        a.push_back(c);
        return a;
    }
};