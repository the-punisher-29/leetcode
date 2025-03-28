class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        vector<pair<int, int>> indexedQueries;
        for (int i = 0; i < k; i++) {
            indexedQueries.push_back({queries[i], i});
        }
        sort(indexedQueries.begin(), indexedQueries.end());
        // Directions for BFS
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        // Result array to store answers in original query order
        vector<int> answer(k);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // Priority queue for BFS
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int points = 0;
        for (auto& [query, originalIndex] : indexedQueries) {
            while (!pq.empty() && pq.top().first < query) {
                auto [currVal, cell] = pq.top();
                pq.pop();
                points++;
                // Explore adjacent cells
                int x = cell.first, y = cell.second;
                for (auto& [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    // Check grid bounds and unvisited cells
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        pq.push({grid[nx][ny], {nx, ny}});
                        visited[nx][ny] = true;
                    }
                }
            }
            // Store points for this query
            answer[originalIndex] = points;
        }
        
        return answer;
    }
};