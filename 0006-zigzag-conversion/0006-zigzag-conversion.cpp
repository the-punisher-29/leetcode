class Solution {
public:
    string convert(string s, int numRows) {
        // If numRows is 1, no conversion is needed
        if (numRows == 1) return s;
        
        // Create a vector of strings to represent each row
        vector<string> rows(min(numRows, int(s.length())));
        
        int curRow = 0;
        bool goingDown = false;
        
        // Iterate through the string, adding each character to the appropriate row
        for (char c : s) {
            rows[curRow] += c;
            
            // Change direction if we're at the top or bottom row
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            
            // Move to the next row
            curRow += goingDown ? 1 : -1;
        }
        
        // Concatenate all rows
        string result;
        for (string row : rows)
            result += row;
        
        return result;
    }
};