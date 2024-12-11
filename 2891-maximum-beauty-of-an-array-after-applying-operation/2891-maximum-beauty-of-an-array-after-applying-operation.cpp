class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxBeauty = 1;  // At least one element can always be in the subsequence
        int left = 0;
        // Sliding window approach
        for (int right = 0; right < nums.size(); right++) {
            // While the difference between max and min exceeds 2k, shrink window
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            // Update max beauty (window size)
            maxBeauty = max(maxBeauty, right - left + 1);
        }
        return maxBeauty;
    }
};