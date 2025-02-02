class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, 0, 0, "", result);
        return result;
    }
private:
    void backtrack(string& num, long target, int index, long eval, long multed,
                  string expr, vector<string>& result) {
        // Base case: reached end of number
        if (index == num.length()) {
            if (eval == target) {
                result.push_back(expr);
            }
            return;
        }
        long curr = 0;
        string currStr;
        for (int i = index; i < num.length(); i++) {
            if (i != index && num[index] == '0') break;
            currStr += num[i];
            curr = curr * 10 + (num[i] - '0');
            // For first number, no operator needed
            if (index == 0) {
                backtrack(num, target, i + 1, curr, curr, currStr, result);
                continue;
            }
            backtrack(num, target, i + 1, eval + curr, curr, 
                     expr + "+" + currStr, result);
            
            backtrack(num, target, i + 1, eval - curr, -curr, 
                     expr + "-" + currStr, result);
            
            backtrack(num, target, i + 1, eval - multed + multed * curr, 
                     multed * curr, expr + "*" + currStr, result);
            if (curr > INT_MAX) break;
        }
    }
};