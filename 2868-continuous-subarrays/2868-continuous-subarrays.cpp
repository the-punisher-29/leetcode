class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long tot_sa = 0;
        int l=0;
        multiset<int> window;
        for (int r=0; r<nums.size(); r++) {
            window.insert(nums[r]);
            while (!window.empty() && *window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[l]));
                l++;
            }
            tot_sa+=r-l+1;
        }
        return tot_sa;
    }
};
//used sliding window and multiset stl