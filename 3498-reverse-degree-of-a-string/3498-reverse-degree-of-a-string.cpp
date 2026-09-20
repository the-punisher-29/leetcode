class Solution {
public:
    int reverseDegree(string s) {
        int tot=0;
        for (int i=0;i<(int)s.size();i++) {
            int rv= 26-(s[i]-'a');
            tot+=rv*(i+1);
        }
        return tot;
    }
};