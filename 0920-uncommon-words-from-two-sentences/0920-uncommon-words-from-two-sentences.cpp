class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        
        // Count words in s1
        countWords(s1, wordCount);
        
        // Count words in s2
        countWords(s2, wordCount);
        
        // Find uncommon words
        vector<string> result;
        for (const auto& pair : wordCount) {
            if (pair.second == 1) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }

private:
    void countWords(const string& s, unordered_map<string, int>& wordCount) {
        istringstream iss(s);
        string word;
        while (iss >> word) {
            wordCount[word]++;
        }
    }
};