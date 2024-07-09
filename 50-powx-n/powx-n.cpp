class Solution {
public:
    double myPow(double x, int n) {
         if (n == INT_MIN) {
            x = 1 / x;
            n = INT_MAX; // Use INT_MAX and multiply by x one more time later
            return myPow(x, n) * x;
        }
        // base case
        if(n ==0){
            return 1.0;
        }

        // handle the negative cases 
        if (n < 0){
            x = 1/x;
            n = -n;
        }
        // recursive calls for the function 
        double half =  myPow(x,  n/2);
        if( n %2 == 0){
            return half*half;

        }else{
            return half*half*x;
        }
    }
};