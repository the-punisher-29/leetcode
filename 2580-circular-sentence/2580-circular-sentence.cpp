class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        
        // Split the sentence into words
        while (ss >> word) {
            words.push_back(word);
        }        
        int n = words.size();
        // Check each word's last character with the next word's first character
        for (int i = 0; i < n; ++i) {
            char lastChar = words[i].back();
            char nextFirstChar = words[(i + 1) % n][0];
            if (lastChar != nextFirstChar) {
                return false;
            }
        }
        return true;
    }
};
