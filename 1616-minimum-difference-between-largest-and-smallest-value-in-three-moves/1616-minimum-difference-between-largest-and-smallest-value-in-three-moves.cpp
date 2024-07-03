class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        
        sort(nums.begin(), nums.end());
        
        int minDiff = INT_MAX;
        
        // Option a: Change three smallest to fourth smallest
        minDiff = min(minDiff, nums[n-1] - nums[3]);
        
        // Option b: Change two smallest to third smallest and largest to fourth largest
        minDiff = min(minDiff, nums[n-2] - nums[2]);
        
        // Option c: Change smallest to second smallest and two largest to third largest
        minDiff = min(minDiff, nums[n-3] - nums[1]);
        
        // Option d: Change three largest to fourth largest
        minDiff = min(minDiff, nums[n-4] - nums[0]);
        
        return minDiff;
    }
};