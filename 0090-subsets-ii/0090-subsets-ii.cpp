class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //emptycse
        if(nums.empty()) return {{}};
        sort(nums.begin(), nums.end());// Sorting to group duplicates
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, 
                   vector<vector<int>>& result) {
        result.push_back(current); // Adding current subset   
        for (int i = start; i < nums.size(); i++) {
            if(i!=start && i>0 && nums[i]==nums[i-1]) continue;
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};