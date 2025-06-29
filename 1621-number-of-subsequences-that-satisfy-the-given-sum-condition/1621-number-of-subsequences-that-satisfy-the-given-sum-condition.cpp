class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1000000007;
        int n = nums.size();
        // Sort the array to use two pointers approach
        sort(nums.begin(), nums.end());
        // Precompute powers of 2 to avoid repeated calculations
        vector<long long> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i-1] * 2) % MOD;
        }
        int left = 0, right = n - 1;
        long long result = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                // All subsequences that include nums[left] and any subset of [left+1, right]
                // Count = 2^(right - left)
                result = (result + power[right - left]) % MOD;
                left++;
            } else {
                // nums[left] + nums[right] > target, so decrease the maximum
                right--;
            }
        } 
        return (int)result;
    }
};