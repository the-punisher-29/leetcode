class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int maxScore = 0;
        int leftZeros = 0;
        int rightOnes = count(s.begin(), s.end(), '1'); // Total ones in string
        
        // For each possible split point except the last position
        for(int i = 0; i < n-1; i++) {
            // Update counts
            if(s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
            
            // Update maximum score
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        
        return maxScore;
    }
};