class Solution {
public:
    int longestPalindrome(std::string s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        
        int length = 0;
        bool odd_found = false;
        
        for (const auto& pair : charCount) {
            if (pair.second % 2 == 0) {
                length += pair.second;
            } else {
                length += pair.second - 1;
                odd_found = true;
            }
        }
        
        if (odd_found) {
            length += 1;
        }
        
        return length;
    }
};
