class Solution {
public:
    string reverseWords(string& s) {
        // Reverse the whole string
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int index = 0;
        
        for (int start = 0; start < n; start++) {
            if (s[start] != ' ') {
                // Move the word to the front
                if (index != 0) s[index++] = ' ';
                
                int end = start;
                while (end < n && s[end] != ' ') {
                    s[index++] = s[end++];
                }
                
                // Reverse the word
                reverse(s.begin() + index - (end - start), s.begin() + index);
                
                start = end;
            }
        }
        
        // Truncate the string to remove any trailing spaces
        s.resize(index);
        
        return s;
    }
};