typedef long long ll;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        ll ec=1;
        ll oc=0;
        ll res=0;
        ll pre_sum=0;
        for(int num:arr){
            pre_sum+=num;
            if(pre_sum%2==0){
                res=(res+oc)%MOD;
                ec++;
            }
            else{
                res=(res+ec)%MOD;
                oc++;
            }
        }
        return res;
    }
};