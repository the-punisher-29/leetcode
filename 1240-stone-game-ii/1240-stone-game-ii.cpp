class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + piles[i];
        }
        // Memoization array 'dp', initialized to 0. Stores the results of subproblems.
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        function<int(int, int)> dfs = [&](int i, int m) -> int {
            // If we're able to take all remaining stones, we'll do so.
            if (m * 2 >= n - i) {
                return prefixSum[n] - prefixSum[i];
            }
            // If we've already computed this subproblem, return the stored result.
            if (dp[i][m] != 0) {
                return dp[i][m];
            }
            int best = 0;
            for (int x = 1; x <= 2 * m; ++x) {
                best = max(best, prefixSum[n] - prefixSum[i] - dfs(i + x, max(x, m)));
            }
            dp[i][m] = best;
            return best;
        };
        return dfs(0, 1);
    }
};