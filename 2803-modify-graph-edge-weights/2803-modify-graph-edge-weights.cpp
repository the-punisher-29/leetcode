class Solution {
private:
    const long long INF = 1e18;
    
    vector<long long> dijkstra(int n, const vector<vector<pair<int, long long>>>& graph, int start) {
        vector<long long> dist(n, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (d > dist[node]) continue;
            
            for (const auto& [next, weight] : graph[node]) {
                long long newDist = dist[node] + weight;
                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    pq.push({dist[next], next});
                }
            }
        }
        
        return dist;
    }
    
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, long long>>> graph(n);
        vector<int> negativeEdges;
        
        // Build the graph and collect negative edges
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            long long w = edges[i][2];
            if (w == -1) {
                negativeEdges.push_back(i);
                w = INF;
            }
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        
        // First pass: set all -1 edges to INF
        vector<long long> dist = dijkstra(n, graph, source);
        if (dist[destination] < target) return {};
        
        // Second pass: try to reduce the weights
        for (int idx : negativeEdges) {
            int u = edges[idx][0], v = edges[idx][1];
            
            for (auto& [adj, weight] : graph[u]) {
                if (adj == v) weight = 1;
            }
            for (auto& [adj, weight] : graph[v]) {
                if (adj == u) weight = 1;
            }
            
            dist = dijkstra(n, graph, source);
            if (dist[destination] <= target) {
                long long need = target - (dist[destination] - 1);
                for (auto& [adj, weight] : graph[u]) {
                    if (adj == v) weight = need;
                }
                for (auto& [adj, weight] : graph[v]) {
                    if (adj == u) weight = need;
                }
                edges[idx][2] = need;
            } else {
                edges[idx][2] = 1;
            }
        }
        
        // Final check
        dist = dijkstra(n, graph, source);
        if (dist[destination] != target) return {};
        
        // Set remaining -1 edges to a large value
        for (auto& edge : edges) {
            if (edge[2] == -1) edge[2] = 2e9;
        }
        
        return edges;
    }
};