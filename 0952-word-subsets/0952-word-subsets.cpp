class Solution {
private:
    vector<int> fc(const string& word) {
        vector<int> freq(26, 0);
        for(char c : word) {
            freq[c - 'a']++;
        }
        return freq;
    }
    bool isSubset(const vector<int>& freq1, const vector<int>& maxFreq2) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] < maxFreq2[i]) return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreqWords2(26, 0);
        for(const string& word : words2) {
            vector<int> freq=fc(word);
            for(int i=0;i<26;i++) {
                maxFreqWords2[i]=max(maxFreqWords2[i],freq[i]);
            }
        }
        vector<string> res;
        for(const string& word : words1) {
            vector<int> freq=fc(word);
            if(isSubset(freq, maxFreqWords2)) {
                res.push_back(word);
            }
        }
        return res;
    }
};