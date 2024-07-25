//apr--taking one ele and then finding rem two using two ptr st sum==0
//here sorting helps avoid duplicates and ease the use of two ptr--avoid brute force of O[n^3] tc
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    res.push_back({nums[i],nums[l],nums[r]});

                    //avoid duplicates
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return res;
    }
};