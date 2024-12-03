class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // Calculate the final length of the modified string
        int originalLength = s.length();
        int numSpaces = spaces.size();
        
        // Create the result string with the correct size
        string result(originalLength + numSpaces, ' ');
        
        // Keep track of the current position in the original string and result string
        int originalIndex = 0;
        int resultIndex = 0;
        
        // Iterate through spaces array
        for (int spaceIndex : spaces) {
            // Copy characters from original string before the space
            while (originalIndex < spaceIndex) {
                result[resultIndex] = s[originalIndex];
                originalIndex++;
                resultIndex++;
            }
            
            // Move to the next space position
            resultIndex++;
        }
        
        // Copy remaining characters after the last space
        while (originalIndex < originalLength) {
            result[resultIndex] = s[originalIndex];
            originalIndex++;
            resultIndex++;
        }
        
        return result;
    }
};