class Solution {
public:
    int minSwaps(string s) {
        int ob=0;
        int sw=0;
        for (char& c : s) {
            if (c == '[') {
                ob++;
            } 
            else if (ob>0) {
                ob--;
            }
        }
        sw=(ob+1)/2;
        return sw;
    }
};