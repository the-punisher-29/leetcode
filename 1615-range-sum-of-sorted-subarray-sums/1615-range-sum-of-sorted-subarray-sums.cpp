typedef long long ll;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD=1e9+7;
        vector<int> subsum;
        for(int i=0;i<n;++i){
            ll curr_sum=0;
            for(int j=i;j<n;++j){
                curr_sum+=nums[j];
                subsum.push_back(curr_sum);
            }
        }
        sort(subsum.begin(),subsum.end());
        ll res=0;
        for(int i=left-1;i<right;++i){
            res=(res+subsum[i])%MOD;
        }
        return res;
    }
};