class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> seen = {{0, -1}};
        int state = 0, maxLen = 0;
        string vowels = "aeiou";
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) {
                    state ^= 1 << j;
                    break;
                }
            }
            
            if (seen.find(state) != seen.end()) {
                maxLen = max(maxLen, i - seen[state]);
            } else {
                seen[state] = i;
            }
        }
        
        return maxLen;
    }
};