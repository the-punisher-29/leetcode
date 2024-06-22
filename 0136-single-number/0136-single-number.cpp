class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int num:nums){
            res=res^num;
        }
        return res;
    }
};
//simple! we have to slove it in O(n) and constant space ---XOR op.
//all repetative ele will become zero and ele occuring only once will be left out in res variable