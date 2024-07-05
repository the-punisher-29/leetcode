class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int count;
        for (int x = 0; x <= n; x++) {
            count = 0;
            // Count the number of elements greater than or equal to x
            for (int i = 0; i < n; i++) {
                if (nums[i] >= x) {
                    count++;
                } else {
                    break;
                }
            }
            // If the count is equal to x, return x
            if (count == x) {
                return x;
            }
        }
        // If no such x is found, return -1
        return -1;
    }
};