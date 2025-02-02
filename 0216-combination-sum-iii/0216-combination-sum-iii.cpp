class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        BT(k, n, 1, curr, res);
        return res;
    }
private:
    void BT(int k, int remainingSum, int start, vector<int>& current, 
                   vector<vector<int>>& result) {
        // Base cases
        if (remainingSum == 0 && current.size() == k) {
            result.push_back(current);
            return;
        }
        if (remainingSum < 0 || current.size() >= k) {
            return;
        }
        // Trying each possible number
        for (int i = start; i <= 9; i++) {
            // Early pruning: if remaining numbers can't sum to target, skip
            if (remainingSum - i < 0) break;
            current.push_back(i);
            BT(k, remainingSum - i, i + 1, current, result);
            current.pop_back();
        }
    }
};