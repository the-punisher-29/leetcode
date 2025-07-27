class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for (int current = 1, previous = 0; current < nums.size() - 1; ++current) {
            if (nums[current] == nums[current + 1]) {
                continue;
            }
            if (nums[current] > nums[previous] && nums[current] > nums[current + 1]) {
                ++count;
            }
            if (nums[current] < nums[previous] && nums[current] < nums[current + 1]) {
                ++count;
            }
            previous = current;
        }
        return count;
    }
};