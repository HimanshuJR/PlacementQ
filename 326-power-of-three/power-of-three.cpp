class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false; // Power of three is only positive
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1; // If n reduces to 1, it's a power of three
    }
};
