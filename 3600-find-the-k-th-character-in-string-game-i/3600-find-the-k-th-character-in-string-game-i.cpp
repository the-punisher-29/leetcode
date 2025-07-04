class Solution{
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            int currentLen = word.length();
            string nextPart = "";
            nextPart.reserve(currentLen); // Reserve space for efficiency
            // Generate next part by transforming each character
            for (int i = 0; i < currentLen; i++) {
                char c = word[i];
                if (c == 'z') {
                    nextPart += 'a';
                } else {
                    nextPart += (c + 1);
                }
            }
            word += nextPart;
        }
        return word[k - 1];
    }
};