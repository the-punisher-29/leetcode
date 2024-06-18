class Solution {
public:
    int romanToInt(string s) {
    map<char, int> ConvMap={{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
    int result = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i > 0 && ConvMap[s[i]] > ConvMap[s[i - 1]]) {
            result += ConvMap[s[i]] - 2 * ConvMap[s[i - 1]];
        } else {
            result += ConvMap[s[i]];
        }
    }
    return result;
}
};