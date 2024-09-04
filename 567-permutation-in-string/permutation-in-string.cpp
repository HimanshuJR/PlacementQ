class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int n = s1.size(); int m = s2.size();
       if( n> m){
        return false;
       }
        
        vector<int> s1count(26,0) ; vector<int> s2count(26,0);
        for(int i = 0;i<n;i++){
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }
        // sliding window 
        for(int i = 0;i<m-n;i++){
            if( s1count == s2count ) return true;
            s2count[s2[i] -'a']--;
            s2count[s2[i+n] -'a']++;
        }
        return s1count == s2count;
    }
};