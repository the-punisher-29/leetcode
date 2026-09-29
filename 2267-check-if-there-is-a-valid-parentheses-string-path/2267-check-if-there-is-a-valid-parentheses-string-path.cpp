class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // quick infeasibility check: total length must be even
        if ((m + n - 1) % 2 != 0) return false;

        // dp[i][j] = set of achievable balances at (i,j), represented as vector<bool>
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxBalance = i + j + 1;
                dp[i][j].assign(maxBalance + 1, false);

                int delta = (grid[i][j] == '(') ? 1 : -1;

                if (i == 0 && j == 0) {
                    if (delta == 1) dp[i][j][1] = true;
                    // if delta == -1, balance would be -1, invalid, leave all false
                    continue;
                }

                // gather balances from top and left
                if (i > 0) {
                    for (int b = 0; b < (int)dp[i-1][j].size(); b++) {
                        if (dp[i-1][j][b]) {
                            int nb = b + delta;
                            if (nb >= 0 && nb <= maxBalance) dp[i][j][nb] = true;
                        }
                    }
                }
                if (j > 0) {
                    for (int b = 0; b < (int)dp[i][j-1].size(); b++) {
                        if (dp[i][j-1][b]) {
                            int nb = b + delta;
                            if (nb >= 0 && nb <= maxBalance) dp[i][j][nb] = true;
                        }
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};