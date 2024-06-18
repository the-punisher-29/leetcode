class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        if (charIndexMap.find(s[end]) != charIndexMap.end()) {
            // If the current character is already in the map,
            // move the start pointer to the next position after
            // the last occurrence of this character.
            start = max(start, charIndexMap[s[end]] + 1);
        }

        // Update the index of the current character
        charIndexMap[s[end]] = end;

        // Update the maximum length if needed
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;       
    }
};