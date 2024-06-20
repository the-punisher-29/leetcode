class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        // Step 2: Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
        
        // Step 3: Convert digits
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Check for overflow/underflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return static_cast<int>(result * sign);
    }
};