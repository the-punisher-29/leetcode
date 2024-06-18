class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return {};

    int maxLen = 1; // length of the longest palindrome found so far
    int start = 0; // starting index of the longest palindrome found so far

    for (int i = 0; i < n; ++i) {
        // Expand around the center for odd-length palindromes
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
                start = left;
            }
            left--;
            right++;
        }

        // Expand around the center for even-length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
                start = left;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLen);
    }
};