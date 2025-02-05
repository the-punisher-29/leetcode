class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        //Finding mismatched indices
        vector<int> diff;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
            // More than 2 mismatches means can't swap to equality
            if (diff.size() > 2) return false;
        }
        //exactly 2 mismatches to swap
        if (diff.size() != 2) return false;
        bool r=(s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
        return r;
    }
};