class Solution {
public:
    int maxFreqSum(string s) {
        int maxv=0;
        int maxc=0;
        int si=s.size();
        unordered_map<int,int> fc;
        for(char c:s){
            fc[c-'a']++;
        }
        //max frequencies for vowels and consonants
        for(auto& pair : fc) {
            int charIndex = pair.first;
            int freq = pair.second;
            char currentChar = 'a' + charIndex;
            if(currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || 
               currentChar == 'o' || currentChar == 'u') {
                maxv = max(maxv, freq);
            } else {
                maxc = max(maxc, freq);
            }
        }
        
        return maxv + maxc;

        
    }
};