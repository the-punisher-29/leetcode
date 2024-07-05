class Solution {
public:
    int minimumLength(std::string s) {
        int left = 0, right = s.length() - 1;
        
        // Continue removing pairs of identical characters from the ends
        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            // Move left pointer to the right until a different character is encountered
            while (left <= right && s[left] == ch) left++;
            // Move right pointer to the left until a different character is encountered
            while (left <= right && s[right] == ch) right--;
        }
        
        // Calculate and return the length of the remaining string
        return right - left + 1;
    }
};