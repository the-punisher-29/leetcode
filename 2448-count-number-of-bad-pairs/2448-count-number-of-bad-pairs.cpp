#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll,ll> count;
        // Counting frequency of (index - value)
        for(int i = 0; i < n; i++) {
            count[i - (ll)nums[i]]++;
        }
        ll tp=(ll)n*(n-1)/2;
        ll gp= 0;
        for(auto& p : count) {
            ll k = p.second;
            gp += (k*(k-1))/2;
        }
        return tp- gp;
    }
};