class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> count(n, 1); // Number of nodes in subtree rooted at each node
        vector<int> ans(n, 0);    // Sum of distances for each node
        // Step 1: Calculate count and ans for each node
        dfs(0, -1, adj, count, ans);
        // Step 2: Update ans for each node
        dfs2(0, -1, adj, count, ans, n);
        return ans;
    }
    
private:
    // DFS to calculate count and ans for each node
    void dfs(int node, int parent, const vector<vector<int>>& adj, vector<int>& count, vector<int>& ans) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, adj, count, ans);
                count[node] += count[neighbor];
                ans[node] += ans[neighbor] + count[neighbor];
            }
        }
    }
    // DFS to update ans for each node
    void dfs2(int node, int parent, const vector<vector<int>>& adj, const vector<int>& count, vector<int>& ans, int n) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                ans[neighbor] = ans[node] - count[neighbor] + n - count[neighbor];
                dfs2(neighbor, node, adj, count, ans, n);
            }
        }
    }
};