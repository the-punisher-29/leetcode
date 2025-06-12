class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int md=0;
        for(int i=0;i<n;++i){
            md=max(md,abs(nums[i]-nums[(i+1)%n]));
        }
        return md;
        
    }
};