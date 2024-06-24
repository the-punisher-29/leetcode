class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flipped(n + 1, 0);  // Difference array to track flips
        int flips = 0;  // Current number of active flips
        int result = 0;  // Total number of flips

        for (int i = 0; i < n; i++) {
            // Update the current number of flips
            flips += flipped[i];
            
            // If the current bit is effectively 0, we need to flip
            if ((nums[i] + flips) % 2 == 0) {
                if (i + k > n) {
                    return -1;  // Can't flip, not enough elements left
                }
                
                flips++;
                if (i + k < n) {
                    flipped[i + k]--;  // Mark the end of this flip
                }
                result++;
            }
        }

        return result;
    }
};