class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            string group = "";
            // Add up to k characters from the current position
            for (int j = 0; j < k; j++) {
                if (i + j < n) {
                    //have characters from original string
                    group += s[i + j];
                } else {
                    // Need to fill with the fill character
                    group += fill;
                }
            }
            result.push_back(group);
        }
        
        return result;
    }
};