class Solution {
public:
    vector<int> values;
    int totalXor;        
    int subtreeXor;     
    int nodeCount;     
    int minDifference = INT_MAX;
    vector<vector<int>> graph;
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        nodeCount = nums.size();
        graph.resize(nodeCount, vector<int>());
        for (auto& e : edges) {
            int from = e[0], to = e[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        totalXor = 0;
        for (int& v : nums) totalXor ^= v;
        values = nums;
        for (int i = 0; i < nodeCount; ++i) {
            for (int neighbor : graph[i]) {
                subtreeXor = dfs(i, -1, neighbor);
                dfs2(i, -1, neighbor);
            }
        }
        return minDifference;
    }
    int dfs(int current, int parent, int excludedNode) {
        int currentXor = values[current];
        for (int next : graph[current])
            if (next != parent && next != excludedNode) 
                currentXor ^= dfs(next, current, excludedNode);
        return currentXor;
    }
    int dfs2(int current, int parent, int excludedNode) {
        int currentXor = values[current];
        for (int next : graph[current])
            if (next != parent && next != excludedNode) {
                int a = dfs2(next, current, excludedNode);
                currentXor ^= a;
                int b = subtreeXor ^ a;
                int c = totalXor ^ subtreeXor;
                int maxPart = max(max(a, b), c);
                int minPart = min(min(a, b), c);
                int difference = maxPart - minPart;
                minDifference = min(minDifference, difference);
            }
        return currentXor;
    }
};