class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int l=0,r=n-1;

        for(int i=n-1;i>=0;i--){
            int ls=pow(nums[l],2);
            int rs=pow(nums[r],2);

            if(ls>rs){
                res[i]=ls;
                l++;
            }
            else{
                res[i]=rs;
                r--;
            }
        }
        return res;
    }
};