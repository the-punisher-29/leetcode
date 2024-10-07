//stack based sol
class Solution {
public:
    int minLength(string s) {
        vector<char> stack;
        
        for (char c : s) {
            if (!stack.empty() && 
                ((c == 'B' && stack.back() == 'A') || 
                 (c == 'D' && stack.back() == 'C'))) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        
        return stack.size();
    }
};