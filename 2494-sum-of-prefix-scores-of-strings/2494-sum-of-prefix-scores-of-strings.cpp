//prefixtree aka trie
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count;
    
    TrieNode() : count(0) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;
        }
    }
    
    int getScore(const string& word) {
        int score = 0;
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                break;
            }
            node = node->children[c];
            score += node->count;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }
        
        vector<int> answer;
        for (const string& word : words) {
            answer.push_back(trie.getScore(word));
        }
        
        return answer;
    }
};