class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }
private:
    void backtrack(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset); // Add the current subset to the result

        for (int i = start; i < nums.size(); i++) {
            currentSubset.push_back(nums[i]); // Include the current element
            backtrack(nums, i + 1, currentSubset, result); // Explore the next element
            currentSubset.pop_back(); // Backtrack: remove the current element to try others
        }
    }
};
