class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> result(n, 0);
        int nonZeroIndex = 0;
        // Copying all non-zero elements to the front of the result array
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                result[nonZeroIndex++] = nums[i];
            }
        }
        return result;
    }
};