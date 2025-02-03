class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;  // Minimum length is always 1
        for (int i = 0; i < n; i++) {
            int currLen = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j-1]) {
                    currLen++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, currLen);
        }
        for (int i = 0; i < n; i++) {
            int currLen = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[j-1]) {
                    currLen++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};