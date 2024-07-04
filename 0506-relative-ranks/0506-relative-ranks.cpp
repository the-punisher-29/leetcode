class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>()); // Sort in descending order

        unordered_map<int, int> rankMap;
        for (int i = 0; i < n; i++) {
            rankMap[sortedScore[i]] = i + 1; // Map score to rank (1-indexed)
        }

        vector<string> result(n);
        for (int i = 0; i < n; i++) {
            int rank = rankMap[score[i]];
            switch (rank) {
                case 1:
                    result[i] = "Gold Medal";
                    break;
                case 2:
                    result[i] = "Silver Medal";
                    break;
                case 3:
                    result[i] = "Bronze Medal";
                    break;
                default:
                    result[i] = to_string(rank);
            }
        }

        return result;
    }
};
