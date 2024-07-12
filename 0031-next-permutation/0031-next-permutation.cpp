class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Find the first pair from right where nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            int j = n - 1;
            // Find the smallest element in the subarray nums[i+1:] that is greater than nums[i]
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            // Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }
        
        // Reverse the subarray nums[i+1:]
        reverse(nums.begin() + i + 1, nums.end());
    }
};