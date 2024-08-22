class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1; // Special case: complement of 0 is 1
        // Convert to binary string
        string binary = "";
        while (n > 0) {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }
        // Flip the bits
        for (char &c : binary) {
            c = (c == '0') ? '1' : '0';
        }
        // Convert back to integer
        int result = 0;
        for (char c : binary) {
            result = result * 2 + (c - '0');
        }
        
        return result;
        
    }
};