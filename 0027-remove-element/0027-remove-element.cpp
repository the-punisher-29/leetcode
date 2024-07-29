class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        ///inital thought ---set all val to some unique val
        //sort
        //return 
        //or hashpmap
        //two ptr
        int k=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};