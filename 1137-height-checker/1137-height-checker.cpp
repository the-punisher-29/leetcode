class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expec;
        for(int i=0;i<heights.size();++i){
            expec.push_back(heights[i]);
        }
        sort(expec.begin(),expec.end());
        int s=expec.size();
        int c{0};
        for(int i=0;i<s;++i){
            if(heights[i]!=expec[i]){
                c++;
            }
        }
        return c;
    }
};