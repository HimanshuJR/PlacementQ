class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        if( n== 0) return 0;
        int maxlength = 1;
        int current_length = 1;
        for(int i = 1;i<n;i++){
            if(s[i]-s[i-1] == 1){
                current_length++;
            }else{
                current_length = 1;
            }
            maxlength = max(maxlength, current_length);
        }
        return maxlength;
    }
};