class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mxs=nums[0];
        int crs=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                crs+=nums[i];
            }
            else{
                crs=nums[i];
            }
            mxs=max(mxs,crs);
        }
        return mxs;
    }
};