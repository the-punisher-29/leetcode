class Solution {
private:
    bool majdur(const string& str1, const string& str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        if (len1>len2) {
            return false;
        }
        bool isPrefix = true;
        for (int i = 0; i < len1; i++) {
            if (str1[i] != str2[i]) {
                isPrefix = false;
                break;
            }
        }
        bool isSuffix = true;
        for (int i = 0; i < len1; i++) {
            if (str1[i] != str2[len2 - len1 + i]) {
                isSuffix = false;
                break;
            }
        }
        return isPrefix && isSuffix;
    }
    
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (majdur(words[i], words[j])) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};