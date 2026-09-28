class Solution {
public:
    int maxDepth(string s) {
        int mD=0;
        int cD=0;
        for(char& c:s){
            if(c=='('){
                cD++;
                mD=max(mD,cD);
            }
            else if(c==')'){
                cD--;
            }
        }
        return mD;
    }
};