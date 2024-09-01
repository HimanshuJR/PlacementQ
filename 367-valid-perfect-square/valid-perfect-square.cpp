class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num <2){
            return true;
        }
        long long left = 2 , right = num/2, guess_squared, mid;
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
};