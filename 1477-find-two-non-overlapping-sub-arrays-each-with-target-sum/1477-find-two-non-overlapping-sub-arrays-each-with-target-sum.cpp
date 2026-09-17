class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        vector<int> dp(n, INF); // dp[i] = min length of valid subarray within arr[0..i]
        int ans = INF;
        int left = 0, sum = 0;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int curLen = right - left + 1;
                if (left > 0 && dp[left - 1] != INF) {
                    ans = min(ans, curLen + dp[left - 1]);
                }
                dp[right] = min((right > 0 ? dp[right - 1] : INF), curLen);
            } else {
                dp[right] = (right > 0 ? dp[right - 1] : INF);
            }
        }
        return ans == INF ? -1 : ans;
    }
};