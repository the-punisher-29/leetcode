class Solution {
private:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
public:
    int minimizeXor(int num1, int num2) {
        int targetBits = countSetBits(num2);
        int result = 0;
        int bitsNeeded = targetBits;
        for (int bit = 31; bit >= 0 && bitsNeeded > 0; bit--) {
            if (num1 & (1 << bit)) {
                result |= (1 << bit);
                bitsNeeded--;
            }
        }
        if (bitsNeeded > 0) {
            for (int bit = 0; bit <= 31 && bitsNeeded > 0; bit++) {
                if (!(num1 & (1 << bit)) && !(result & (1 << bit))) {
                    result |= (1 << bit);
                    bitsNeeded--;
                }
            }
        }
        return result;
    }
};