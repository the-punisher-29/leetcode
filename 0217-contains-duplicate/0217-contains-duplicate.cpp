class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>fmap;
        for(int nu:nums){
            fmap[nu]+=1;
        }
        for(int nu:nums){
            if(fmap[nu]>=2){
                return true;
            }
        }
        return false;
    }
};