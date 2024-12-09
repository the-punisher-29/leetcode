class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> violations;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] % 2) == (nums[i-1] % 2)) {
                violations.push_back(i-1);
            }
        }
        vector<bool> answer;
        for (const auto& query : queries) {
            int from = query[0], to = query[1];
            // Check if any parity violation exists in the subarray
            auto it = lower_bound(violations.begin(), violations.end(), from);
            // If violation exists and is within the query range, it's not special
            answer.push_back(
                it == violations.end() || *it >= to
            );
        }
        
        return answer;
    }
};