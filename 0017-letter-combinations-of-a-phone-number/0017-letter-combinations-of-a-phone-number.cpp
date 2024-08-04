class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};//bc
        bktrk(digits,0);
        return res;
    }
private:
    vector<string> res;
    string curr;
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    void bktrk(const string &digits,int index){
        if(index==digits.length()){
            if(!curr.empty()){
                res.push_back(curr);
            }
            return;
        }
        for(char l:digitToLetters[digits[index]]){
            curr.push_back(l);
            bktrk(digits,index+1);
            curr.pop_back();
        }
    }
};