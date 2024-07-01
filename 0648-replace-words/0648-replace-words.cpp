class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Create a set to store the dictionary words for efficient lookup
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        // Create a vector to store the words in the sentence
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Replace the derivatives with roots
        for (auto& word : words) {
            string root = word;
            for (int i = 1; i <= word.length(); i++) {
                string prefix = word.substr(0, i);
                if (rootSet.count(prefix)) {
                    root = prefix;
                    break;
                }
            }
            word = root;
        }
        
        // Combine the words back into a sentence
        stringstream result;
        for (int i = 0; i < words.size(); i++) {
            result << words[i];
            if (i != words.size() - 1) {
                result << " ";
            }
        }
        return result.str();
    }
};