class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lastSeenPositionInS[256];
        int lastSeenPositionInT[256];
      
        int length = s.length();
      
        for (int i = 0; i < length; ++i) {
            char charFromS = s.at(i);
            char charFromT = t.at(i);
            if (lastSeenPositionInS[charFromS] != lastSeenPositionInT[charFromT]) {
                return false;
            }
            lastSeenPositionInS[charFromS] = i + 1;
            lastSeenPositionInT[charFromT] = i + 1;
        }
        return true;
    }
        
    };