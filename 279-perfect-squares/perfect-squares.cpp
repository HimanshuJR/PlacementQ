class Solution {
public:
bool isPerfectSquare(int num) {
        if( num <2){
            return true;
        }
        long left = 2 , right = num/2, guess_squared, mid;
        while(left <= right){
            mid = (left + right)/2;
            guess_squared = mid*mid;
            if(guess_squared == num){
                return true;
            }else if(guess_squared > num ){
                right = mid -1;
            }else{
                left = mid+1;
            }
        }
        return false;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
           
        }
};