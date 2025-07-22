class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        //find max_sum__unique_subarray and return its sum
        //prefixsum as per ritual
        //using array -> fuck vector supremacy
        int prefixSum[n+1];
        prefixSum[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        //freq array
        int frequency[10001]{0};
        int maxSum=0;
        int si=0;
        //slider
        for (int i = 1; i <= n; ++i) {
            int currentValue = nums[i - 1];
            si= max(si, frequency[currentValue]);
            maxSum = max(maxSum, prefixSum[i] - prefixSum[si]);
            frequency[currentValue] = i;
        }
        return maxSum;
    }    
};