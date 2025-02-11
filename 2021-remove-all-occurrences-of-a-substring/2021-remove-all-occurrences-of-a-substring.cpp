class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<char>st;
        int pl= part.length();
        for(char c : s) {
            st.push_back(c);
            if(st.size()>= pl) {
                bool isMatch=true;
                for(int i = 0; i < pl; i++) {
                    if(st[st.size()-pl+i]!=part[i]) {
                        isMatch = false;
                        break;
                    }
                }
                if(isMatch) {
                    for(int i = 0; i <pl; i++) {
                        st.pop_back();
                    }
                }
            }
        }
        return string(st.begin(), st.end());
    }
};