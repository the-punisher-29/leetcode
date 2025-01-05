class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<long long> shiftCount(n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            int value = (direction == 1) ? 1 : -1;
            shiftCount[start] += value;
            shiftCount[end + 1] -= value;
        }
        for (int i = 1; i < n; i++) {
            shiftCount[i] += shiftCount[i - 1];
        }
        string result = s;
        for (int i = 0; i < n; i++) {
            long long totalShift = (shiftCount[i] % 26 + 26) % 26;
            int newChar = ((s[i] - 'a' + totalShift) % 26);
            result[i] = 'a' + newChar;
        }
        return result;
    }
};