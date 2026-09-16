class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (n < k) return 0;
        // isPal[i][j] = true if s[i..j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) isPal[i][i] = true;
        for (int i = 0; i + 1 < n; i++) isPal[i][i+1] = (s[i] == s[i+1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                isPal[i][j] = (s[i] == s[j]) && isPal[i+1][j-1];
            }
        }
        // dp[i] = max substrings selected from s[i..n-1]
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1]; // skip i
            // find earliest j such that s[i..j] is a palindrome of length >= k
            for (int len = k; i + len - 1 < n; len++) {
                int j = i + len - 1;
                if (isPal[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                    break; // shortest valid palindrome from i is enough
                }
            }
        }
        return dp[0];
    }
};