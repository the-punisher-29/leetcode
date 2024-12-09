class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tempMax = currMax;
            currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], tempMax * nums[i], currMin * nums[i]});  
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};