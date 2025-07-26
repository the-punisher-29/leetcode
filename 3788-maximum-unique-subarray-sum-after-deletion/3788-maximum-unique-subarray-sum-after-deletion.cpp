typedef long long ll;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> used;
        ll sum = 0;
        bool hasNonNeg = false;
        for (int x : nums) {
            if (x >= 0 && used.find(x) == used.end()) {
                used.insert(x);
                sum += x;
                hasNonNeg = true;
            }
        }
        if (hasNonNeg)
            return sum;
        return *max_element(nums.begin(), nums.end());
    }
};