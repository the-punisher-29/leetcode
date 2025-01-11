class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;//edge case
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int oc=0;
        for (int count:freq) {
            if (count % 2 == 1) {
                oc++;
            }
        }
        // If number of characters with odd frequency is greater than k,
        // impossible to construct k palindromes
        // (each odd frequency character must be in middle of a different palindrome)
        if (oc>k) return false;
        // If we reach here, we can construct k palindromes
        // Maximum palindromes possible = string length
        // Minimum palindromes possible = number of characters with odd frequency
        // (or 1 if all characters have even frequency)
        return k>=oc;
    }
};