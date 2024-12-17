class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string result = "";
        while (true) {
            bool found = false;
            for (int i = 25; i >= 0; i--) {
                if (freq[i] == 0) continue;
                if (result.empty() || result.back() != (i + 'a')) {
                    int count = min(freq[i], repeatLimit);
                    for (int j = 0; j < count; j++) {
                        result += (char)(i + 'a');
                    }
                    freq[i] -= count;
                    found = true;
                    break;
                }
                else {
                    for (int j = i - 1; j >= 0; j--) {
                        if (freq[j] > 0) {
                            result += (char)(j + 'a');
                            freq[j]--;
                            found = true;
                            break;
                        }
                    }
                    break;
                }
            }
            if (!found) break;
        }
        return result;
    }
};