class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build adjacency list representation of the graph
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Initialize visited array and queue for BFS
        vector<bool> visited(n, false);
        queue<int> bfsQueue;
        bfsQueue.push(source);
        visited[source] = true;
        
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            
            // Check if current vertex is the destination
            if (currentVertex == destination)
                return true;
            
            // Explore neighbors of current vertex
            for (int neighbor : graph[currentVertex]) {
                if (!visited[neighbor]) {
                    bfsQueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        // If destination not found after traversing reachable vertices
        return false;
    }
};