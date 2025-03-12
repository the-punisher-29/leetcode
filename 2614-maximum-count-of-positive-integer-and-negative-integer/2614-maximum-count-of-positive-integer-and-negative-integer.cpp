class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //bs-as logn
        int n = nums.size();
        int firstNonNegative = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int firstPositive = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int nc=firstNonNegative;
        int pc=n-firstPositive;
        return max(nc,pc);
    }
};