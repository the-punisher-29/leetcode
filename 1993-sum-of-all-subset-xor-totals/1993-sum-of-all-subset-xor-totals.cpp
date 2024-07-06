class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalXORSum = 0;
        // Iterate through all possible subsets
        for (int mask = 0; mask < (1 << n); mask++) {
            int xorTotal = 0;
            
            // Calculate the XOR total for the current subset
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    xorTotal ^= nums[i];
                }
            }
            
            totalXORSum += xorTotal;
        }
        
        return totalXORSum;
    }
};