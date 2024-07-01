class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> prefixSumCnt;
        int sum=0;
        int cnt=0;
        prefixSumCnt[0]=1;
        for(int num:nums){
            sum=sum+num;
            cnt=cnt+prefixSumCnt[sum-goal];
            prefixSumCnt[sum]++;
        }
        return cnt;
    }
};