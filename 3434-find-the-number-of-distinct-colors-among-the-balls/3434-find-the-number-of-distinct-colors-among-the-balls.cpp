class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
         int n = queries.size();
        vector<int> res(n);
        unordered_map<int, int> bc;
        unordered_map<int, int> cc;
        for(int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int newColor = queries[i][1];
            if(bc.count(ball)) {
                int oldColor = bc[ball];
                cc[oldColor]--;
                if(cc[oldColor] == 0) {
                    cc.erase(oldColor);
                }
            }
            bc[ball] = newColor;
            cc[newColor]++;
            res[i] =cc.size();
        }
        return res;
    }
};