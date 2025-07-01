class Solution{
public:
    int possibleStringCount(string word) {
        int count = 1; // Count the original string
        int n = word.length();
        // Scan for consecutive identical characters
        for (int i = 0; i < n; ) {
            int j = i;
            // Find the end of current consecutive group
            while (j < n && word[j] == word[i]) {
                j++;
            }
            int groupLength = j - i;
            if (groupLength > 1) {
                // Alice could have intended 1, 2, ..., groupLength-1 characters
                // for this group (groupLength is already counted)
                count += (groupLength - 1);
            }
            i = j; // Move to next different character
        }
        return count;
    }
};