class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());//sorting fo bs
        long long count = 0;
        int n = nums.size();
        //for each num check
        for (int i = 0; i < n - 1; i++) {
            // Find the range of indices j where lower <= nums[i] + nums[j] <= upper
            // This means: lower - nums[i] <= nums[j] <= upper - nums[i]
            // Find first index where nums[j] >= lower - nums[i]
            int lowerBound = lower - nums[i];
            auto leftIt = lower_bound(nums.begin() + i + 1, nums.end(), lowerBound);
            
            // Find first index where nums[j] > upper - nums[i]
            int upperBound = upper - nums[i];
            auto rightIt = upper_bound(nums.begin() + i + 1, nums.end(), upperBound);
            // Add the number of elements in range [leftIt, rightIt)
            count += rightIt - leftIt;
        }
        return count;
    }
};