class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const long long MOD = 1000000007;
        int n = (int)words.size();
        int m = (int)words[0].size();
        int t = (int)target.size();

        // Precompute frequency of each character at every column
        // freq[col][ch] = how many times character ch appears in column col
        vector<vector<long long>> freq(m, vector<long long>(26, 0));
        for(int col = 0; col < m; col++){
            for(int i = 0; i < n; i++){
                char c = words[i][col];
                freq[col][c - 'a']++;
            }
        }

        // dp[i][j] = number of ways to form target[0..i-1] using columns [0..j-1]
        vector<vector<long long>> dp(t + 1, vector<long long>(m + 1, 0));

        // Base case: dp[0][j] = 1 for all j (forming empty prefix in any columns)
        for(int j = 0; j <= m; j++){
            dp[0][j] = 1;
        }

        // Fill dp
        for(int i = 1; i <= t; i++){
            for(int j = 1; j <= m; j++){
                // We can skip this column
                dp[i][j] = dp[i][j - 1];
                // Or use this column if it has the needed character
                char c = target[i - 1];
                long long count = freq[j - 1][c - 'a'];
                // Add dp[i-1][j-1] * count of this character in col (j-1)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * count) % MOD;
            }
        }

        return (int)dp[t][m];
    }
};