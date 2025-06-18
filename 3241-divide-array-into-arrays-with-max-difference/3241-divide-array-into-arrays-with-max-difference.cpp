class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result;
        
        // Sort the array to minimize differences within groups
        sort(nums.begin(), nums.end());
        
        // Try to form groups of 3 consecutive elements
        for (int i = 0; i < n; i += 3) {
            vector<int> group = {nums[i], nums[i + 1], nums[i + 2]};
            
            // Check if the difference between max and min in this group is <= k
            int maxVal = *max_element(group.begin(), group.end());
            int minVal = *min_element(group.begin(), group.end());
            
            if (maxVal - minVal > k) {
                // If any group violates the condition, return empty array
                return {};
            }
            
            result.push_back(group);
        }
        
        return result;
    }
};