class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // dp[i] means if s[0:i] can be segmented into words from dictionary
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;  // Empty string is always valid
        // For each position in string
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                // If s[0:j] is valid and s[j:i] is in dictionary
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};