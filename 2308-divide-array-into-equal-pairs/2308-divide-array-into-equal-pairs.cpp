class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int>cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        for (auto& pair : cnt) {
            if (pair.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};