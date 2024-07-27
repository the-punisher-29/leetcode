class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        //creating a  2d matrix to store all coversion costs
        vector<vector<int>> minCost(26, vector<int>(26, INF));
        // same char cost obv 0
        for (int i = 0; i < 26; i++) {
            minCost[i][i] = 0;
        }
        for (int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            minCost[from][to] = min(minCost[from][to], cost[i]);
        }
        // Floyd-Warshall algorithm
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }
        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (from == to) continue;
            if (minCost[from][to] == INF) return -1;
            totalCost += minCost[from][to];
        }
        
        return totalCost;
    }
};