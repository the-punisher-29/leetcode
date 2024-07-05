class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for(char c:s){
            if(stk.empty() || abs(stk.top() -c) !=32){
                stk.push(c);
            }
            else{
                stk.pop();
            }
        }
        string str="";
        while(!stk.empty()){
            str=stk.top()+str;
            stk.pop();
        }
        return str;
    }
};