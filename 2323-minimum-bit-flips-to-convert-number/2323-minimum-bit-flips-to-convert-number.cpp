class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        return __builtin_popcount(xorResult);
    }
};