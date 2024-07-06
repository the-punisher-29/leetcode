class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int s_len = s.length(), t_len = t.length();
        
        while (i < s_len && j < t_len) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }
        
        // The number of characters left in t that were not matched in s
        return t_len - j;
    }
};
