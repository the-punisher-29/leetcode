class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        auto digitSum = [](int x) {
            int s = 0;
            while (x > 0) { s += x % 10; x /= 10; }
            return s;
        };
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            int da = digitSum(nums[a]), db = digitSum(nums[b]);
            if (da != db) return da < db;
            return nums[a] < nums[b];
        });
        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || order[i] == i) continue;
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = order[j];
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};