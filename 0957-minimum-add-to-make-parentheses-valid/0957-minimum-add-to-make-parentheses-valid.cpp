class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;  // Count of open parentheses that need to be closed
        int additions = 0;  // Count of parentheses we need to add
        
        for (char c : s) {
            if (c == '(') {
                open++;
            } else if (c == ')') {
                if (open > 0) {
                    open--;
                } else {
                    additions++;
                }
            }
        }
        
        return additions + open;
    }
};