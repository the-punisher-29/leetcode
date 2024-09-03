class Solution {
public:
    int getLucky(string s, int k) {
        string converted = "";
        
        // Convert step
        for (char c : s) {
            int num = c - 'a' + 1;
            converted += to_string(num);
        }
        
        int result = 0;
        
        // Initial transform
        for (char digit : converted) {
            result += digit - '0';
        }
        
        // Subsequent transforms
        for (int i = 1; i < k; i++) {
            int sum = 0;
            while (result > 0) {
                sum += result % 10;
                result /= 10;
            }
            result = sum;
        }
        
        return result;
    }
};