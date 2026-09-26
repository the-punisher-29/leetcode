class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> know;
        for (auto& kv : knowledge) {
            know[kv[0]] = kv[1];
        }
        string result;
        result.reserve(s.size());
        string key;
        bool inBracket = false;
        for (char c : s) {
            if (c == '(') {
                inBracket = true;
                key.clear();
            } else if (c == ')') {
                inBracket = false;
                auto it = know.find(key);
                result += (it != know.end()) ? it->second : "?";
            } else if (inBracket) {
                key += c;
            } else {
                result += c;
            }
        }
        return result;
    }
};