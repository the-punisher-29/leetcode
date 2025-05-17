class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        // Lambda function to check if two strings differ by exactly one character
        auto canFormSequence = [](const string& left, const string& right) {
            if (left.size() != right.size()) {
                return false;
            }
            int diffCount = 0;
            for (int i = 0; i < left.size(); ++i) {
                diffCount += left[i] != right[i];
            }
            return diffCount == 1;
        };
        vector<int> longestSubsequenceLength(n, 1);
        vector<int> previousIndex(n, -1);
        int maxLength = 1; // To keep track of the overall max length of subsequences
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && longestSubsequenceLength[i] < longestSubsequenceLength[j] + 1 && canFormSequence(words[i], words[j])) {
                    longestSubsequenceLength[i] = longestSubsequenceLength[j] + 1;
                    previousIndex[i] = j;
                    maxLength = max(maxLength, longestSubsequenceLength[i]);
                }
            }
        }
        vector<string> result;
        int maxIndex = -1;
        for (int i = 0; i < n; ++i) {
            if (longestSubsequenceLength[i] == maxLength) {
                maxIndex = i;
                break;
            }
        }
        for (int j = maxIndex; j != -1; j = previousIndex[j]) {
            result.push_back(words[j]);
        }
        // As we traced back, the sequence will be in reverse; we need to reverse it again
        reverse(result.begin(), result.end());
        return result;
    }
};