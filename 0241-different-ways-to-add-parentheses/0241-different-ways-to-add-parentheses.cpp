class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return computeWithMemo(expression);
    }

private:
    unordered_map<string, vector<int>> memo;
    
    vector<int> computeWithMemo(const string& expr) {
        // Check if we've already computed this subexpression
        if (memo.count(expr)) return memo[expr];
        
        vector<int> result;
        
        // Base case: if the expression is a single number
        if (expr.find_first_of("+-*") == string::npos) {
            result.push_back(stoi(expr));
            return result;
        }
        
        // Recursive case
        for (int i = 0; i < expr.length(); i++) {
            char c = expr[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = computeWithMemo(expr.substr(0, i));
                vector<int> right = computeWithMemo(expr.substr(i + 1));
                
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') result.push_back(l + r);
                        else if (c == '-') result.push_back(l - r);
                        else if (c == '*') result.push_back(l * r);
                    }
                }
            }
        }
        
        // Memoize the result for this subexpression
        memo[expr] = result;
        return result;
    }
};