class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        // Helper function to calculate distances from a starting node
        auto getDistances = [&](int start) -> vector<int> {
            vector<int> dist(n, -1); // -1 means unreachable
            int curr = start;
            int d = 0;
            // Follow the path until we reach end or cycle
            while (curr != -1 && dist[curr] == -1) {
                dist[curr] = d;
                curr = edges[curr];
                d++;
            }
            
            return dist;
        };
        // Get distances from both starting nodes
        vector<int> dist1 = getDistances(node1);
        vector<int> dist2 = getDistances(node2);
        int result = -1;
        int minMaxDist = INT_MAX;
        // Check all nodes to find the optimal meeting point
        for (int i = 0; i < n; i++) {
            // Node must be reachable from both starting nodes
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                // Update result if we found a better solution
                // (smaller max distance, or same max distance with smaller index)
                if (maxDist < minMaxDist) {
                    minMaxDist = maxDist;
                    result = i;
                }
            }
        }
        return result;
    }
};