class Solution {
public:
    bool checkValidString(string s) {
        int bal=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]!=')'){
                ++bal;
            }
            else if(bal>0){
                --bal;
            }
            else{
                return false;
            }
        }
        bal=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]!='('){
                ++bal;
            }
            else if(bal>0){
                --bal;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};