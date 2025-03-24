class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //ADJ LIST
        vector<vector<pair<int, long long>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time}); // bi-directional road
        }
        //djikstra
        const int MOD = 1e9 + 7;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;   
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [curr_dist, curr] = pq.top();
            pq.pop();
            if (curr_dist > dist[curr]) continue;
            for (auto& [next, time] : graph[curr]) {
                long long new_dist = curr_dist + time;
                if (new_dist < dist[next]) {
                    dist[next] = new_dist;
                    ways[next] = ways[curr];
                    pq.push({new_dist, next});
                }
                else if (new_dist == dist[next]) {
                    ways[next] = (ways[next] + ways[curr]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};