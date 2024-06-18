class Solution {
public:
    bool isValid(string s) {
        //such a noob!!
        // int n=s.size();
        // bool val;
        // for(int i=0;i<n;i+=2){
        //     if(s[i]=='(' && s[i+1]==')' || s[i]=='{' && s[i+1]=='}' || s[i]=='[' && s[i+1]==']'){
        //         val=1;
        //     }
        //     else{
        //         val=0;
        //     }
        // }
        // return val;
        stack<char> sam;
        for(char c:s){
            if (c == '(' || c == '{' || c == '[') {
                sam.push(c);
            }
            else{
                if(sam.empty()){
                    return false;
                }
            char top=sam.top();
            sam.pop();
            if((c==')' && top!='(') || (c=='}'&& top!='{') || (c==']' && top!='[')){
                return false;
            }
        }
    }
    return sam.empty();
    }
};