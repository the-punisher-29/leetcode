class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        string res;
        int q = sum / 9, r = sum % 9;
        res.append(q, '9');
        if (r > 0) res += char('0' + r);
        res.append(num - (int)res.size(), '0');
        return res;
    }
};