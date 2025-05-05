class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        // For small cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        // dp[i][j] represents the number of ways to tile a 2xi board with state j
        // j = 0: fully covered
        // j = 1: top cell of column i is covered
        // j = 2: bottom cell of column i is covered
        vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
        // Base cases
        dp[1][0] = 1; // One vertical domino
        dp[1][1] = 0; // Can't have just top covered
        dp[1][2] = 0; // Can't have just bottom covered
        dp[2][0] = 2; // Two vertical dominoes or two horizontal dominoes
        dp[2][1] = 1; // One tromino with bottom right missing
        dp[2][2] = 1; // One tromino with top right missing
        for (int i = 3; i <= n; i++) {
            // Fully covered state
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
            // Top row covered state
            dp[i][1] = (dp[i-1][2] + dp[i-2][0]) % MOD;
            // Bottom row covered state
            dp[i][2] = (dp[i-1][1] + dp[i-2][0]) % MOD;
        }
        
        return dp[n][0];
    }
};