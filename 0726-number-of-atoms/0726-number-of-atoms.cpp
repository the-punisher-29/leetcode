// islower and is upper fn from cctype
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});
        int i = 0, n = formula.length();
        
        while (i < n) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            } else if (formula[i] == ')') {
                auto top = st.top();
                st.pop();
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                if (num == 0) num = 1;
                for (auto& [atom, count] : top) {
                    st.top()[atom] += count * num;
                }
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) j++;
                string atom = formula.substr(i, j - i);
                i = j;
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                if (num == 0) num = 1;
                st.top()[atom] += num;
            }
        }
        
        map<string, int> counts = st.top();
        string result;
        for (auto& [atom, count] : counts) {
            result += atom;
            if (count > 1) {
                result += to_string(count);
            }
        }
        return result;
    }
};