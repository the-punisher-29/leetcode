class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        // dp[i][0] = length of longest alternating subsequence ending at index i with groups value 0
        // dp[i][1] = length of longest alternating subsequence ending at index i with groups value 1
        vector<vector<int>> dp(n, vector<int>(2, 1));
        // prev[i][j] stores the previous index in the optimal subsequence
        vector<vector<int>> prev(n, vector<int>(2, -1));
        int maxLength = 1;
        int endIndex = 0;
        int endGroup = groups[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If current and previous groups are different
                if (groups[i] != groups[j]) {
                    // If adding the current element to the subsequence ending at j improves length
                    if (dp[j][groups[j]] + 1 > dp[i][groups[i]]) {
                        dp[i][groups[i]] = dp[j][groups[j]] + 1;
                        prev[i][groups[i]] = j;
                        // Update max length and end point if this is the longest so far
                        if (dp[i][groups[i]] > maxLength) {
                            maxLength = dp[i][groups[i]];
                            endIndex = i;
                            endGroup = groups[i];
                        }
                    }
                }
            }
        }
        // Reconstruct the subsequence
        vector<string> result;
        while (endIndex != -1) {
            result.push_back(words[endIndex]);
            endIndex = prev[endIndex][endGroup];
            if (endIndex != -1) {
                endGroup = groups[endIndex];
            }
        }
        // Reverse since we built it backwards
        reverse(result.begin(), result.end());
        return result;
    }
};