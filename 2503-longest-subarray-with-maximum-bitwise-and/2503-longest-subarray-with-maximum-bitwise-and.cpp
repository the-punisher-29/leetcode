class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int currentLength = 0;
        int maxLength = 0;
        for (int num : nums) {
            if (num == maxElement) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 0;
            }
        }
        return maxLength;
    }
};