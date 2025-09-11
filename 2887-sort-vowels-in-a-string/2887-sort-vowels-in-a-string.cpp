class Solution {
public:
    string sortVowels(string s) {
        string vowels;
        for (char c : s) {
            char lowerChar = tolower(c);
            if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u') {
                vowels.push_back(c);
            }
        }
        ranges::sort(vowels);
        int vowelIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            char lowerChar = tolower(s[i]);
            if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u') {
                s[i] = vowels[vowelIndex++];
            }
        }
        return s;
    }
};