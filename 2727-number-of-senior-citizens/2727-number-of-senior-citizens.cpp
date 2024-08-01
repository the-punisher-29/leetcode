class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt{0};
        for(auto info:details){
            string req=info.substr(11,2);
            int num=stoi(req);
            if(num>60){
                cnt++;
            }
        }
        return cnt;
    }
};