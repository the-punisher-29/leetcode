class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int left = 0, right = 0;
        int maxLength = 0, currentCost = 0;

        while (right < n) {
            currentCost += abs(s[right] - t[right]); 

            while (currentCost > maxCost) { // Shrink window if cost exceeds limit
                currentCost -= abs(s[left] - t[left]);
                left++;
            }

            maxLength = max(maxLength, right - left + 1); // Update max length
            right++; 
        }

        return maxLength;
    }
};
