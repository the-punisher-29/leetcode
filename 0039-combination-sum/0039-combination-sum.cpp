class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            // If the current candidate is greater than the remaining sum, break
            if (candidates[i] > remain) break;
            current.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};