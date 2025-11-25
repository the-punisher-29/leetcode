// class Solution {
// public:
//     int triangularSum(vector<int>& nums) {
//         int n=nums.size();
//         // if(n==1) return nums[0];
//         vector<int> newn(n-1);
//         while(n!=1){
//             // vector<int> newn(n-1,0);
//             if(n==1) return newn[0];
//             for(size_t i=0;i<n-1;i++){
//                 newn[i]=(nums[i]+nums[i+1])%10;
//             }
//             n--;
//         }
//         return newn[0];
//     }
// };
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            for (size_t i = 0; i < n - 1; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            --n;
        }
        return nums[0];
    }
};
