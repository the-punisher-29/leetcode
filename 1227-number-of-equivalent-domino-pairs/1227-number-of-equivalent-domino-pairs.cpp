class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> counts;
        int result = 0;
        for (const auto& domino : dominoes) {
            int key = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
            result += counts[key];
            counts[key]++;
        }
        
        return result;
    }
};