class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int n = nums.size();
        int minIndex = -1, maxIndex = -1, lastInvalidIndex = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalidIndex = i;
            } else {
                if (nums[i] == minK) {
                    minIndex = i;
                }
                if (nums[i] == maxK) {
                    maxIndex = i;
                }
                int left = lastInvalidIndex + 1;
                int right = min(minIndex, maxIndex);
                count += max(0, right - left + 1);
            }
        }

        return count;
    }
};