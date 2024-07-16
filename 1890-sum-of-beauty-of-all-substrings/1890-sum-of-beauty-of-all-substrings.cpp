class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);  // Frequency count for each character
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;  // Increment frequency of current character
                
                int minFreq = INT_MAX, maxFreq = 0;
                
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                        maxFreq = max(maxFreq, freq[k]);
                    }
                }
                
                result += maxFreq - minFreq;
            }
        }
        
        return result;
    }
};
//sliding window approach