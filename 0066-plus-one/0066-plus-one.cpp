class Solution {
public:
    bool chk9(vector<int> &digits){
        for(int nu:digits){
            if(nu!=9){
                return false;
            }
        }
        return true;
    }
    vector<int> plusOne(vector<int>& digits) {
        int sz=digits.size();
        int idx=0;
        if(chk9(digits)){
            // vector<int>ans= new vector<int>ans(sz+1,0);
            vector<int> ans;
            ans.resize(sz + 1, 0);
            ans[0]=1;
            for(int i=1;i<ans.size();++i){
                ans[i]=0;
            }
            return ans;
        }
        else{
            if(digits[sz-1]!=9){
                digits[sz-1]++;
                return digits;
            }
            else{
                for(int i=sz-1;i>=0;--i){
                    if(digits[i]==9){
                        digits[i]=0;
                        idx=i;
                    }
                    else{
                        break;
                    }
                }
                digits[idx-1]++;
                return digits;
            }        
        }
    }
};