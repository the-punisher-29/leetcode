class Solution {
public:
    int minMaxDifference(int num) {
        // Convert the input number to a string
        string numStr = to_string(num);
        // Create a copy of the string for later modification
        string maxStr = numStr;
        // Get the first digit of the string
        char firstDigit = numStr[0];
        // Replace all occurrences of the first digit with '0' to create the minimum possible number
        for (char& c : numStr) {
            if (c == firstDigit) {
                c = '0';
            }
        }
        // Convert the modified string back to an integer to obtain the minimum number
        int minNum = stoi(numStr);
        // Iterate over the characters in the copy of the original number string
        for (int i = 0; i < maxStr.size(); ++i) {
            // If a character is not '9', it can be replaced with '9' to maximize the number
            if (maxStr[i] != '9') {
                char currentDigit = maxStr[i];
                // Replace all occurrences of the current digit with '9'
                for (int j = i; j < maxStr.size(); ++j) {
                    if (maxStr[j] == currentDigit) {
                        maxStr[j] = '9';
                    }
                }
                // Convert the maximized string back to an integer and return the difference
                return stoi(maxStr) - minNum;
            }
        }
        // If all characters were '9', return the difference between the original number and the minimum number
        return num - minNum;
    }
};