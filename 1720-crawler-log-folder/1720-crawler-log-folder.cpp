class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        
        for (const string& operation : logs) {
            if (operation == "../") {
                if (depth > 0) {
                    depth--;
                }
            } else if (operation == "./") {
                // Do nothing
            } else {
                depth++;
            }
        }
        
        return depth;
    }
};