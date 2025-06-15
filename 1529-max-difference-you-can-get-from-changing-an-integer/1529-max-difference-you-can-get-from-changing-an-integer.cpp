class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        // Create max number (a)
        string maxStr = s;
        for (int i = 0; i < maxStr.length(); i++) {
            if (maxStr[i] != '9') {
                char target = maxStr[i];
                // Replace all occurrences of this digit with '9'
                for (int j = 0; j < maxStr.length(); j++) {
                    if (maxStr[j] == target) {
                        maxStr[j] = '9';
                    }
                }
                break;
            }
        }
        
        // Create min number (b)
        string minStr = s;
        if (minStr[0] != '1') {
            // First digit is not 1, replace it with 1
            char target = minStr[0];
            for (int j = 0; j < minStr.length(); j++) {
                if (minStr[j] == target) {
                    minStr[j] = '1';
                }
            }
        } else {
            // First digit is 1, find first digit that's not 0 or 1
            for (int i = 1; i < minStr.length(); i++) {
                if (minStr[i] != '0' && minStr[i] != '1') {
                    char target = minStr[i];
                    // Replace all occurrences with '0'
                    for (int j = 0; j < minStr.length(); j++) {
                        if (minStr[j] == target) {
                            minStr[j] = '0';
                        }
                    }
                    break;
                }
            }
        }
        
        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);
        
        return maxNum - minNum;
    }
};