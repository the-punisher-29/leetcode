class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int result = 0;
        vector<bool> visited(n, false);
        function<long long(int)> dfs = [&](int node) -> long long {
            visited[node] = true;
            long long subtreeSum = values[node];
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    long long childSum = dfs(neighbor);
                    if (childSum % k == 0) {
                        result++;
                    } else {
                        subtreeSum += childSum;
                    }
                }
            }
            return subtreeSum;
        };
        long long totalSum = dfs(0);
        if (totalSum % k == 0) {
            result++;
        }
        return result;
    }
};