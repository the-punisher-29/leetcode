class Solution {
public:
    bool canChange(string start, string target) {
        // If the non-blank characters are different, return false
        if (removeUnderscores(start) != removeUnderscores(target)) {
            return false;
        }
        
        int n = start.length();
        int j = 0; // Target string index
        
        for (int i = 0; i < n; i++) {
            // Skip blanks in start string
            if (start[i] == '_') continue;
            
            // Find next non-blank character in target
            while (j < n && target[j] == '_') j++;
            
            // Check movement constraints
            if (j == n || start[i] != target[j]) {
                return false;
            }
            
            // Validate piece movement direction
            if (start[i] == 'L' && i < j) {
                return false; // 'L' can only move left
            }
            if (start[i] == 'R' && i > j) {
                return false; // 'R' can only move right
            }
            
            j++;
        }
        
        return true;
    }
    
private:
    // Remove underscore characters to compare piece composition
    string removeUnderscores(string s) {
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        return s;
    }
};