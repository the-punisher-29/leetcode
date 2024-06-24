class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.length()) {
            return "0";
        }
        vector<char> stack;
        for (char digit : num) {
            while (k > 0 && !stack.empty() && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }
        while (k > 0) {
            stack.pop_back();
            k--;
        }
        string result;
        for (char digit : stack) {
            result.push_back(digit);
        }
        result.erase(0, result.find_first_not_of('0'));
        return result.empty() ? "0" : result;
    }
};