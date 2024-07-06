class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size()),rightSum(nums.size()),answer(nums.size());

        int sum=0;
        for(int i=0;i<nums.size();++i){
            leftSum[i]=sum;
            sum=sum+nums[i];
        }

        sum=0;
        for(int i=nums.size()-1;i>=0;--i){
            rightSum[i]=sum;
            sum=sum+nums[i];
        }

        for(int i=0;i<nums.size();++i){
            answer[i]=abs(leftSum[i]-rightSum[i]);
        }
        return answer; 
    }
};