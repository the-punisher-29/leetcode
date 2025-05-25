class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        //f-count
        for (const string& word : words) {
            count[word]++;
        }
        int result = 0;
        bool hasMiddle = false;
        for (auto& [word, freq] : count) {
            if (word[0] == word[1]) {
                // Symmetric word (like "aa", "bb")
                // Use pairs for left and right sides
                result += (freq / 2) * 4;
                // If there's an odd count and we haven't used a middle yet
                if (freq % 2 == 1 && !hasMiddle) {
                    result += 2;
                    hasMiddle = true;
                }
            } else {
                // Asymmetric word (like "ab")
                string reverse = string(1, word[1]) + string(1, word[0]);
                if (count.find(reverse) != count.end()) {
                    // Only count once to avoid double counting
                    if (word < reverse) {
                        result += min(freq, count[reverse]) * 4;
                    }
                }
            }
        }
        return result;
    }
};