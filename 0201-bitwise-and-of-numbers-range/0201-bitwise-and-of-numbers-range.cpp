class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    // Find the common prefix of binary representation of left and right
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    // Shift left back to obtain the result
    return left << shift;
   }
};