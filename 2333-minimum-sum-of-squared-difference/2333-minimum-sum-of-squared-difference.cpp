class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        int mx = 0;
        for (int i = 0; i < n; i++) mx = max(mx, abs(nums1[i] - nums2[i]));
        vector<long long> cnt(mx + 2, 0);
        for (int i = 0; i < n; i++) cnt[abs(nums1[i] - nums2[i])]++;
        for (int v = mx; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            long long c = cnt[v];
            if (k >= c) {
                k -= c;
                cnt[v - 1] += c;
                cnt[v] = 0;
            } else {
                cnt[v - 1] += k;
                cnt[v] -= k;
                k = 0;
            }
        }
        long long ans = 0;
        for (int v = 1; v <= mx; v++) ans += cnt[v] * v * v;
        return ans;
    }
};