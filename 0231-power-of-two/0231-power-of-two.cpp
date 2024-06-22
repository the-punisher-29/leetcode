class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;   // check for positive nos then perform bitwise and for even or we can say power of two  
     }
};