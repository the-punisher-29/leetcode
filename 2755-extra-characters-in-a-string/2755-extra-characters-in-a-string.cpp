class Solution {
public:
    int minExtraChar(string s,vector<string>& dictionary) {
        int n = s.size();
        // Convert the dictionary into a set for faster lookup
        unordered_set<string>dict(dictionary.begin(),dictionary.end());
        // dp[i] will store the minimum extra characters left for substring s[i..n-1]
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            // By default, assume that the current character is an extra character
            dp[i] = 1 + dp[i + 1];
            // Try to match each dictionary word starting from index i
            for (const string& word : dict) {
                int len = word.size();
                if (i + len <= n && s.substr(i, len) == word) {
                    dp[i] = std::min(dp[i], dp[i + len]);
                }
            }
        }
        return dp[0];
    }
};