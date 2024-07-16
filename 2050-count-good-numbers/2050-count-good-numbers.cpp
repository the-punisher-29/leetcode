#define ll long long 
class Solution {
public:
    const int MOD=1e9+7;
    ll pwr(ll b,ll ex){
        ll res=1;
        while(ex>0){
            if(ex & 1){
                res=(res*b)%MOD;
            }
            b=(b*b)%MOD;
            ex>>=1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll even=(n+1)/2;
        ll odd=n/2;
        return ((pwr(5,even))* pwr(4,odd))%MOD;
        
    }
};