class Solution {
public:
    bool isValid(const string& s) {
        int bal = 0;
        for (char c : s) {
            if (c == '(') bal++;
            else if (c == ')') bal--;
            if (bal < 0) return false;
        }
        return bal == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        visited.insert(s);
        queue<string> q;
        q.push(s);
        vector<string> result;
        bool found = false;
        while (!q.empty()) {
            int sz = q.size();
            vector<string> levelValid;
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (isValid(cur)) {
                    levelValid.push_back(cur);
                    found = true;
                }
                if (found) continue;
                for (int j = 0; j < (int)cur.size(); j++) {
                    if (cur[j] != '(' && cur[j] != ')') continue;
                    string next = cur.substr(0, j) + cur.substr(j + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            if (found) {
                return levelValid;
            }
        }
        return result; // shouldn't reach here given constraints (empty string is always valid)
    }
};