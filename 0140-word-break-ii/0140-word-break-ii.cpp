class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // Hash set for faster lookups
        vector<vector<string>> dp(s.size() + 1); // DP table to store valid sentences for each prefix
        dp[0] = {""}; // Base case: empty string has one valid sentence (itself)

        // Dynamic programming to build up valid sentences
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j].empty() && dict.count(s.substr(j, i - j))) {
                    for (const string& sentence : dp[j]) {
                        dp[i].push_back(sentence + (sentence.empty() ? "" : " ") + s.substr(j, i - j));
                    }
                }
            }
        }

        return dp[s.size()]; // Valid sentences for the entire string
    }
};
