class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2) return false;
        int balance = 0;
        int flexible = 0;
        for(int i = 0; i < n; i++) {
            if(locked[i] == '0') {
                flexible++;
            } else if(s[i] == '(') {
                balance++;
            } else {
                balance--;
            }
            if(balance + flexible < 0) {
                return false;
            }
        }
        balance = 0;
        flexible = 0;
        for(int i = n-1; i >= 0; i--) {
            if(locked[i] == '0') {
                flexible++;
            } else if(s[i] == ')') {
                balance++;
            } else {
                balance--;
            }
            if(balance + flexible < 0) {
                return false;
            }
        }
        return true;
    }
};