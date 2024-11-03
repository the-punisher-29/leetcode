class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        if (s.length() == 0) return true;
        //simple--we can concatenate the given s and if the goal is in there then true else false
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};