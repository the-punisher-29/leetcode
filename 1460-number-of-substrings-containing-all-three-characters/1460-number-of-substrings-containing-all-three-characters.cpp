class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<int> charCount(3, 0);
        int left = 0;
        for (int right = 0; right < n; right++) {
            charCount[s[right] - 'a']++;
            while (charCount[0] > 0 && charCount[1] > 0 && charCount[2] > 0) {
                count += n - right;
                charCount[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};