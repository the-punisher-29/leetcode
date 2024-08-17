class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //since array is sorted --first min and last max
        int res=0;
        int min_val = arrays[0][0];
        int max_val = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            res = max({res, abs(arrays[i].back() - min_val),abs(max_val - arrays[i][0])});
            min_val = min(min_val, arrays[i][0]);//overall min
            max_val = max(max_val, arrays[i].back());//overall max
        }
        return res;
    }
};