class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //adj list
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //tracking visited nodes
        vector<bool> visited(n, false);
        int completeCount = 0;
        //chk connec compo
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, graph, visited, component);
                if (comchk(component, graph)) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }
    
private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, component);
            }
        }
    }

    bool comchk(vector<int>& component, vector<vector<int>>& graph) {
        int size = component.size();
        //complete graph with n ver has n*n-1/2 ed
        int totalEdges = 0;
        unordered_set<int> componentSet(component.begin(), component.end());
        for (int node : component) {
            for (int neighbor : graph[node]) {
                if (componentSet.count(neighbor) && node < neighbor) {
                    totalEdges++;
                }
            }
        }
        return totalEdges == (size * (size - 1)) / 2;
    }
};