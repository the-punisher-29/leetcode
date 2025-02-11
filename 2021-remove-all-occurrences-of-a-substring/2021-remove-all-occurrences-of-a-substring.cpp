class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<char> stack;
        int partLen = part.length();
        for(char c : s) {
            stack.push_back(c);
            if(stack.size() >= partLen) {
                bool isMatch = true;
                for(int i = 0; i < partLen; i++) {
                    if(stack[stack.size() - partLen + i] != part[i]) {
                        isMatch = false;
                        break;
                    }
                }
                
                // If match found, remove part
                if(isMatch) {
                    for(int i = 0; i < partLen; i++) {
                        stack.pop_back();
                    }
                }
            }
        }
        
        // Convert stack back to string
        return string(stack.begin(), stack.end());
    }
};