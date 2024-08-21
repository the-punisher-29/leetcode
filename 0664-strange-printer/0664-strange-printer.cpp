class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // Remove consecutive duplicate characters
        string str;
        for (char c : s) {
            if (str.empty() || c != str.back()) {
                str.push_back(c);
            }
        }
        n = str.length();
        
        // dp[i][j] represents the minimum number of turns to print str[i] to str[j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize base case: single character
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill dp table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = len; // Worst case: print each character separately
                
                for (int k = i; k < j; k++) {
                    int total = dp[i][k] + dp[k+1][j];
                    if (str[i] == str[j]) {
                        total--; // Can print str[j] together with str[i]
                    }
                    dp[i][j] = min(dp[i][j], total);
                }
            }
        }
        
        return dp[0][n-1];
    }
};