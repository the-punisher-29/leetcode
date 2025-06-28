
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        // Create pairs of (value, index) to track original positions
        vector<pair<int, int>> valueIndex;
        for (int i = 0; i < n; i++) {
            valueIndex.push_back({nums[i], i});
        }
        // Sort by value in descending order to get largest elements first
        sort(valueIndex.begin(), valueIndex.end(), greater<pair<int, int>>());
        // Take the indices of the k largest elements
        vector<int> selectedIndices;
        for (int i = 0; i < k; i++) {
            selectedIndices.push_back(valueIndex[i].second);
        }
        // Sort indices to maintain original order
        sort(selectedIndices.begin(), selectedIndices.end());
        // Build result array using sorted indices
        vector<int> result;
        for (int idx : selectedIndices) {
            result.push_back(nums[idx]);
        }
        return result;
    }
};