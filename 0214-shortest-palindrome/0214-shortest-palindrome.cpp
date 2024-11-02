class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Create a new string with a separator to avoid overlapping
        string combined = s + "#" + rev_s;
        
        // KMP table
        int n = combined.size();
        vector<int> lps(n, 0);

        // Building the KMP table
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                ++j;
            }
            lps[i] = j;
        }

        // Length of the longest palindromic prefix
        int longest_palindromic_prefix_length = lps[n - 1];
        
        // Characters to be added in front of `s` to make it a palindrome
        string to_add = rev_s.substr(0, s.size() - longest_palindromic_prefix_length);
        
        return to_add + s;
    }
};
