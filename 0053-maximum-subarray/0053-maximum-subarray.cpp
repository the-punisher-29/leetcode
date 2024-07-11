class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];  // Initialize maxSum with the first element
        int currentSum = nums[0];  // Initialize currentSum with the first element
        
        for (int i = 1; i < nums.size(); i++) {
            // Choose between extending the previous subarray or starting a new subarray
            currentSum = max(nums[i], currentSum + nums[i]);
            
            // Update maxSum if currentSum is greater
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};

//kadane's algo***