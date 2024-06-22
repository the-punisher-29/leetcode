class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        int oddCount = 0;
        int result = 0;
        
        // Calculate prefix sum of odd numbers
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (nums[i] % 2);
        }
        
        // Count subarrays with k odd numbers
        unordered_map<int, int> count;
        count[0] = 1;  // Initialize with 0 odd numbers seen
        
        for (int i = 1; i <= n; i++) {
            if (prefixSum[i] >= k) {
                result += count[prefixSum[i] - k];
            }
            count[prefixSum[i]]++;
        }
        
        return result;
    }
};