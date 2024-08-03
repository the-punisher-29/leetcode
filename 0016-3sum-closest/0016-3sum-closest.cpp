class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cs=nums[0]+nums[1]+nums[2];//ini
        for(int i=0;i<n-2;++i){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int curr_sum=nums[i]+nums[l]+nums[r];
                if(curr_sum==target){
                    return curr_sum;
                }
                if(abs(curr_sum-target)<abs(cs-target)){
                    cs=curr_sum;
                }
                if(curr_sum<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return cs;
    }
};