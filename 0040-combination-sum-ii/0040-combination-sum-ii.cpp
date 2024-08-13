class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
private:
    void backtrack(const vector<int>& candidates, int remain, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i-1]) continue;
            // If the current candidate is greater than the remaining sum, break
            if (candidates[i] > remain) break;
            current.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
};