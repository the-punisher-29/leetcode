class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < n; i++) {
            valueToIndex[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLength = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int prev = arr[j] - arr[i];
                if (prev < arr[i] && valueToIndex.count(prev)) {
                    int k = valueToIndex[prev];
                    dp[i][j] = dp[k][i] == 0 ? 3 : dp[k][i] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }
        return maxLength;
    }
};