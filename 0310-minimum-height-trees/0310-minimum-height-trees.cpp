class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};//base case handling
        vector<unordered_set<int>> graph(n);
        vector<int> degrees(n, 0);
        // Build the graph and calculate node degrees
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
            degrees[u]++;
            degrees[v]++;
        }
        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                leaves.push(i);
            }
        }
        // Trim leaves iteratively
        while (n > 2) {
            int leavesSize = leaves.size();
            n -= leavesSize;
            for (int i = 0; i < leavesSize; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : graph[leaf]) {
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        // Remaining nodes are the MHT roots
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};