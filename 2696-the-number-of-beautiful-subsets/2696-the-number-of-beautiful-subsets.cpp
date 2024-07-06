class Solution {
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        return dfs(nums, k, 0, count) - 1; // Subtract 1 to exclude the empty subset
    }

private:
    int dfs(const vector<int>& nums, int k, int index, unordered_map<int, int>& count) {
        if (index == nums.size()) {
            return 1; // This subset is valid
        }
        
        // Option 1: Skip the current element
        int totalCount = dfs(nums, k, index + 1, count);

        // Option 2: Include the current element if it's valid
        int current = nums[index];
        if (count[current - k] == 0 && count[current + k] == 0) {
            count[current]++;
            totalCount += dfs(nums, k, index + 1, count);
            count[current]--;
        }
        
        return totalCount;
    }
};