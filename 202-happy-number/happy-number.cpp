class Solution {
    private:
    int getSquareSum(int n){
         int currnum = 0;
        while( n != 0){
            int digit = n%10;
            currnum += digit*digit;
            n/= 10;
        }
        return currnum;
    }
public:
    bool isHappy(int n) {
        int slow = getSquareSum(n);
        int fast = getSquareSum(getSquareSum(n));

        while((slow != fast) && (fast != 1)) {
            slow = getSquareSum(slow);
            fast = getSquareSum(getSquareSum(fast));
        }
        return fast == 1 ;
    }
};