class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        bt(nums, 0, currentSubset, result);
        return result;
    }
private:
    void bt(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);
        for (int i = start; i < nums.size(); i++) {
            currentSubset.push_back(nums[i]);
            bt(nums, i + 1, currentSubset, result);//going to next ele
            currentSubset.pop_back();//removing curr and exp aaspas
        }
    }
};
