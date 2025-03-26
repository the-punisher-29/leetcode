class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        //prep
        vector<int> nums;
        for (const auto& row : grid) {
            for (int num : row) {
                nums.push_back(num);
            }
        }
        sort(nums.begin(), nums.end());//mnO(log(mn))
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[0]) % x != 0) {
                return -1;
            }
        }
        int median = nums[nums.size() / 2];
        int totalOperations = 0;
        for (int num : nums) {
            int diff = abs(num - median);
            if (diff % x != 0) {
                return -1;
            }
            totalOperations += diff / x;
        }
        return totalOperations;
    }
};