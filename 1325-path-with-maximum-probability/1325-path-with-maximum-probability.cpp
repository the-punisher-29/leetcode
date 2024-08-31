class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Create adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }
        
        // Initialize probabilities
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        
        // Priority queue to store {probability, node}
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // If we've reached the end node, return the probability
            if (node == end_node) {
                return prob;
            }
            
            // If we've found a path with lower probability, skip
            if (prob < maxProb[node]) {
                continue;
            }
            
            // Explore neighbors
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }
        
        // If we can't reach the end node, return 0
        return 0.0;
    }
};