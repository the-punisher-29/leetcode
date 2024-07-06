
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int v = -1;//flag
        for(int i = 0; i < word.length(); ++i) {
            if(word[i] == ch){
                v = i;
                break;
            }
        }
        if (v != -1) {
            for(int i = 0; i <= v / 2; ++i) {
                swap(word[i], word[v - i]);
            }
        }
        return word;
    }
};