class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int groupsCount = 1;
        int currentGroupStart = nums[0];
        for (int& currentNum : nums) {
            // If the difference between the current number and the start of the current group
            // is greater than k, a new group must be started.
            if (currentNum - currentGroupStart > k) {
                currentGroupStart = currentNum;
                groupsCount++;
            }
        }
        return groupsCount;
    }
};