class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> ps(sz);  // ps[i] = max(nums[0..i])
        vector<int> ss(sz);  // ss[i] = min(nums[i..sz-1])
        ps[0] = nums[0];
        for (int i = 1; i < sz; ++i) {
            ps[i] = max(ps[i - 1], nums[i]);
        }
        ss[sz - 1] = nums[sz - 1];
        for (int i = sz - 2; i >= 0; --i) {
            ss[i] = min(ss[i + 1], nums[i]);
        }
        for (int i = 0; i < sz; ++i) {
            if (ps[i] - ss[i] <= k) return i;
        }
        return -1;
    }
};