class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfNumber = false;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const std::string& num) {
        TrieNode* node = root;
        for (char ch : num) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfNumber = true;
    }
    
    int searchLongestPrefix(const std::string& num) {
        TrieNode* node = root;
        int commonLength = 0;
        for (char ch : num) {
            if (node->children.find(ch) != node->children.end()) {
                commonLength++;
                node = node->children[ch];
            } else {
                break;
            }
        }
        return commonLength;
    }
};

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        Trie trie;
        
        // Insert all numbers from arr2 into the Trie
        for (int num : arr2) {
            trie.insert(std::to_string(num));
        }
        
        int maxLength = 0;
        
        // For each number in arr1, find the longest common prefix with any number in arr2
        for (int num : arr1) {
            int currentLCP = trie.searchLongestPrefix(std::to_string(num));
            maxLength = std::max(maxLength, currentLCP);
        }
        
        return maxLength;
    }
};
