class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges){
        //toposort and dp
        int numVertices = colors.size();
        vector<vector<int>> graph(numVertices); // Adjacency list representation of graph
        vector<int> inDegree(numVertices); // In-degree of each vertex
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from].push_back(to);
            ++inDegree[to];
        }
        queue<int> processingQueue;
        vector<vector<int>> dp(numVertices, vector<int>(26)); // DP table: dp[i][c] represents max count of color c in vertex i's paths
        for (int i = 0; i < numVertices; ++i) {
            if (inDegree[i] == 0) {
                processingQueue.push(i);
                int colorIndex = colors[i] - 'a'; 
                dp[i][colorIndex]++;
            }
        }
        int processedCount = 0;
        int maxPathValue = 1;
        while (!processingQueue.empty()) {
            int currentVertex = processingQueue.front();
            processingQueue.pop();
            ++processedCount;
            // Update DP table for neighbors and detect cycles
            for (int neighbor : graph[currentVertex]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    processingQueue.push(neighbor);
                }
                int neighborColorIndex = colors[neighbor] - 'a';
                for (int color = 0; color < 26; ++color) {
                    dp[neighbor][color] = max(dp[neighbor][color], dp[currentVertex][color] + (neighborColorIndex == color));
                    maxPathValue = max(maxPathValue, dp[neighbor][color]);
                }
            }
        }
        //if dag then ok,else fuck no
        return processedCount == numVertices ? maxPathValue : -1;
    }
};
