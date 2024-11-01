class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1; // To count consecutive characters

        // Start with the first character
        result += s[0];

        for (int i = 1; i < s.size(); ++i) {
            // If current character is the same as the previous
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1; // Reset count for a new character
            }

            // Add character only if count is less than 3
            if (count < 3) {
                result += s[i];
            }
        }

        return result;
    }
};
