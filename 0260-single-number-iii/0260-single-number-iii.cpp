class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        
        // Step 1: Find the XOR of all numbers
        for (int num : nums) {
            xor_all ^= num;
        }
        
        // Handle the case where xor_all is INT_MIN
        if (xor_all == INT_MIN) {
            int num1 = 0;
            for (int num : nums) {
                if (num == INT_MIN) {
                    num1 = INT_MIN;
                    break;
                }
            }
            int num2 = 0;
            for (int num : nums) {
                if (num != INT_MIN) {
                    num2 ^= num;
                }
            }
            return {num1, num2};
        }
        
        // Step 2: Find the rightmost set bit in the XOR result
        int rightmost_set_bit = xor_all & (-xor_all);
        
        int num1 = 0, num2 = 0;
        
        // Step 3: Partition the numbers into two groups based on the rightmost set bit
        for (int num : nums) {
            if (num & rightmost_set_bit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};