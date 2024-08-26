class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int max_r=nums[0];
        int jumps=1;
        int steps=nums[0];
        for(int i=1;i<n;++i){
            if(i==n-1){
                return jumps;
            }
            max_r=max(max_r,i+nums[i]);
            steps--;
            if(steps==0){
                jumps++;
                steps=max_r-i;
            }
        }
        return 0;
    }
};