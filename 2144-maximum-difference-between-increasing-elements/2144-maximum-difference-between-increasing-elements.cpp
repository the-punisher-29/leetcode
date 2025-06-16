class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;
        int minSoFar = nums[0];
        
        for (int j = 1; j < n; j++) {
            if (nums[j] > minSoFar) {
                maxDiff = max(maxDiff, nums[j] - minSoFar);
            }
            minSoFar = min(minSoFar, nums[j]);
        }
        
        return maxDiff;
    }
};