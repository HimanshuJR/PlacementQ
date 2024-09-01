class Solution {
public:
    bool isPerfectSquare(int num) {
        long n ;
        if( num == 1){
            return true;
        }
        for(long n  = 1;n <num;n++){
        if(n*n == num){
            return true;
        }
    }
    return false;
    }
};