class Solution {
public:
    string clearStars(string s) {
        vector<int> freq(26, 0); // frequency of each character
        string stack;
        
        for (char c : s) {
            if (c == '*') {
                if (!stack.empty()) {
                    // Find the smallest character that exists
                    for (int i = 0; i < 26; i++) {
                        if (freq[i] > 0) {
                            char minChar = 'a' + i;
                            // Remove the rightmost occurrence of this character
                            for (int j = stack.length() - 1; j >= 0; j--) {
                                if (stack[j] == minChar) {
                                    stack.erase(stack.begin() + j);
                                    freq[i]--;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
            } else {
                stack.push_back(c);
                freq[c - 'a']++;
            }
        }
        return stack;
    }
};