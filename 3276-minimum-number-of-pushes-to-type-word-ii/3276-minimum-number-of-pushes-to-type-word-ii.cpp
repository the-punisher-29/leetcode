class Solution {
public:
    int minimumPushes(string word) {
        // Count frequency of each character
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort frequencies in descending order
        sort(freq.rbegin(), freq.rend());
        
        int total_pushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;  // No more characters to process
            
            // Calculate number of pushes for this character
            int pushes = (i / 8) + 1;  // 8 keys available (2-9)
            total_pushes += freq[i] * pushes;
        }
        
        return total_pushes;
    }
};