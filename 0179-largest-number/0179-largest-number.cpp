class Solution {
public:
    static bool comp(string a ,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for(auto num:nums){
             res.push_back(to_string(num));
        }
        sort(res.begin(),res.end(),comp);
        if(res[0]=="0"){
        return "0";
        }
        string op;
        for(auto i:res){
            op+=i;
        }
        return op;
    }
// private:
//     bool comp(string a ,string b){
//         return a+b>b+a;
//     }
};