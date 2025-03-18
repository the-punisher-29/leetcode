class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ml= 1;
        int l=0;
        int usedBits =0;
        for (int r=0;r< n;r++) {
            // While the current number has bits that conflict with the subarray
            while ((usedBits & nums[r]) != 0) {
                usedBits ^= nums[l];
                l++;
            }
            usedBits|=nums[r];
            ml= max(ml, r-l+1);
        }
        return ml;
    }
};