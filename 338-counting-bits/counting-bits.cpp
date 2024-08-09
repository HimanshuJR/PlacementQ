class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int offset = 1;
        for(int i = 1;i<=n;i++){
            if( i == offset *2){
                offset = i;
            }
            ans[i] = ans[i-offset] +1;
        }
        return ans;
    }
};