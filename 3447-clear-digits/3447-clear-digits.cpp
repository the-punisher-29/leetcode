class Solution {
public:
    string clearDigits(string s) {
        //stk
        vector<char>st;
        for(char c:s){
            if(!isdigit(c)){
                st.push_back(c);
            }
            else{
                if(!st.empty()){
                    st.pop_back();
                }
            }
        }
        return string(st.begin(),st.end());
    }
};